#!/usr/bin/php5
<?php
/*
 * PIP v0.5.3
 */

//Start the Session

// Defines
define('ROOT_DIR', realpath(dirname(__FILE__)) .'/');
define('APP_DIR', ROOT_DIR .'application/');

// Includes
require_once(APP_DIR .'config/config.php');
require_once(ROOT_DIR .'system/model.php');
require_once(ROOT_DIR .'system/view.php');
require_once(ROOT_DIR .'system/controller.php');
require_once(ROOT_DIR .'system/pip.php');

require_once(APP_DIR .'helpers/auth_helper.php');
require_once(APP_DIR .'helpers/files_helper.php');
require_once(APP_DIR .'helpers/util.php');
require_once(APP_DIR .'helpers/timer.php');
require_once(APP_DIR .'helpers/log.class.php');
require_once(APP_DIR .'models/DBCtrl.php');

declare( ticks = 1 );

// register signal handler
pcntl_signal( SIGALRM, "signal_handler", false );
pcntl_signal( SIGHUP, 'signal_handler', false );
pcntl_signal( SIGTERM, 'signal_handler', false );

$signal_flag = false;    //Signal status flag, to justify whether we received the kill -1 signal

function signal_handler( $signal ) {
	global $signal_flag;
	switch( $signal ){
	case SIGQUIT:
	case SIGTERM:
		$signal_flag = true;
		break;
	case SIGSTOP:
		break;
	case SIGHUP:
		break;
	case SIGALRM:
		break;
	default:
		break;
	}
}

$timer;
$cmd = array();
$create;
$max_id = 0;
$execmd = array();

function handler_init()
{
	global $timer;
	global $create;
	global $cmd;
	global $max_id;

	$create = new DBCtrl;
	$create->Init();
	$timer = new Timer;
	$timer->Init();
	$timer->registerTimer("10s", 10);

	$data = $create->GetUserFirst(time() - 5 * 3600);
	$tmp = array();
	foreach ($data as $val)
	{
		$tmp[] = array('role_id' => $val[0],
			'name' => $val[1],
			'gm_auth' => $val[2],
			'status' => $val[3],
			'progress' => $val[4],
			'level' => $val[5],
			'gold' => $val[6],
			'diamond' => $val[7],
			'cur_stage' => $val[8],
			'cur_train' => $val[9],
			'vip_level' => $val[10],
			'vip_exp' => $val[10],
			'stamina' => $val[11],
			'energy' => $val[12],
			'quest' => $val[13],
			'last_login_time' => $val[14],
			'diamond_pay' => $val[15]
			);
		if ($val[0] > $max_id)
			$max_id = $val[0];
	}
	$cmd = array_merge($cmd, $tmp);
	log::write("init cmd max_id {$max_id} size " . count($cmd));
}

function handler_process()
{
	global $timer;
	global $cmd;
	global $create;
	global $max_id;
	global $execmd;
	global $signal_flag;
	global $config;

	if (!$signal_flag)
	{
		if ($timer->IsArriveTimer("10s", true))
		{
			$data = $create->GetUserAll($max_id);
			$tmp = array();
			foreach($data as $val)
			{
				$tmp[] = array('role_id' => $val[0],
					'name' => $val[1],
					'gm_auth' => $val[2],
					'status' => $val[3],
					'progress' => $val[4],
					'level' => $val[5],
					'gold' => $val[6],
					'diamond' => $val[7],
					'cur_stage' => $val[8],
					'cur_train' => $val[9],
					'vip_level' => $val[10],
					'vip_exp' => $val[10],
					'stamina' => $val[11],
					'energy' => $val[12],
					'quest' => $val[13],
					'last_login_time' => $val[14],
					'diamond_pay' => $val[15]
				);
				if ($val[0] > $max_id)
					$max_id = $val[0];
			}
			$cmd = array_merge($cmd, $tmp);
			log::write("get cmd max_id {$max_id} size " . count($cmd));
		}
	}
	else
	{
		if (empty($execmd))
		{
			return 1;
		}
	}
	log::write("cmd size " . count($cmd));

	foreach($cmd as $val)
	{
		$execmd[] = array('data' => $val,
						  'status' => 0
		);
	}
	$cmd = array();
	
	foreach($execmd as &$val)
	{
		log::write("send data result role_id " . $val['data']['role_id']);
		//todo send static stat	
		$data = "role_id\001name\001gm_auth\001status\001progress\001level\001gold\001diamond\001cur_stage\001cur_train\001vip_level\001vip_exp\001stamina\001energy\001quest\001last_login_time\001diamond_pay\n";
		$data .= implode($val['data'], "\001") . "\n";
		$meta = array('appkey' => $config['mz_app_key'],
					  'tid'	=>	$config['mz_app_id'],
					  'checkinfo' => md5($config['mz_check_key'] . $config['mz_app_key'] . $val['data']['role_id']),
					  'product_code' => 'game',
					  'reqid'	=> $val['data']['role_id'],
					  'md5code'	=> md5($data),
					  'date_time' => '',
					  'version' => 1.0,
					  'compress' => 'none',
					  'itype' => "1",
					  'allcount' => '',
					  'cur_stageNo' => '',
					  'pageSize' => ''
		);
		$ret = Util::post($config['mz_stat_url'], $data, true, $meta);
		$val['status'] = 2;
		log::write("data " . $data);
		log::write("checkinfo " . md5($config['mz_check_key'] . $config['mz_app_key'] . $config['mz_app_id']));
		log::write("send data result " . $ret);
	}

	foreach($execmd as $key => &$val)
	{
		if ($val['status'] == 2 || $val['status'] == 1)
		{
			array_splice($execmd, $key, 1);
		}
	}
	return 0;
}

function handler_final()
{
}

function daemon()
{
	log::write("start daemon");
	//global $signal_flag;
	//$pid = pcntl_fork(); // fork
	//if ($pid < 0)
		//exit;
	//else if ($pid) // parent
		//exit;
	//else { // child

		//$sid = posix_setsid();
		//#chdir("/"); 
		//#fclose(STDIN);
		//#fclose(STDOUT);
		//#fclose(STDERR);
		//#$STDIN = fopen('/dev/null', 'r');
		//#$STDOUT = fopen('log/out.log', 'wb');
		//#$STDERR = fopen('log/error.log', 'wb');
		//if ($sid < 0)
			//exit;
		handler_init();
		//while(1)
		//{
			////log::write("========");
			$ret = handler_process();
			//usleep(2000000);			
			//if ($ret == 1)
				//return;
		//}
	//}
	handler_final();
}

ini_set('display_errors', 0);
ini_set('error_log', 'log/sys.log');
daemon();
?>
