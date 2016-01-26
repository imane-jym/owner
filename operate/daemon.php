#!/usr/bin/php
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
	$create->CreateInitTable();
	$timer = new Timer;
	$timer->Init();
	$timer->registerTimer("10s", 10);

	$data = $create->GetJobbyPending(0);
	$tmp = array();
	foreach ($data as $val)
	{
		$tmp[] = array('id' => $val[0],
			'module_id' => $val[1],
			'param' => $val[2],
			'create_time' => $val[3],
			'create_user_id' => $val[4],
			'job_content' => $val[5],
			'result' => $val[6],
			'status' => $val[7],
			'type' => $val[8],
			'main_param' => $val[9],
			'dirty' => false,
			);
		if ($val[0] > $max_id)
			$max_id = $val[0];
	}
	$cmd = array_merge($cmd, $tmp);
	log::write("init cmd max_id {$max_id}" . print_r($cmd, true));
}

function handler_process()
{
	global $timer;
	global $cmd;
	global $create;
	global $max_id;
	global $execmd;
	global $signal_flag;

	if (!$signal_flag)
	{
		if ($timer->IsArriveTimer("10s", true))
		{
			$data = $create->GetJobbyPending($max_id);
			$tmp = array();
			foreach($data as $val)
			{
				$tmp[] = array('id' => $val[0],
					'module_id' => $val[1],
					'param' => $val[2],
					'create_time' => $val[3],
					'create_user_id' => $val[4],
					'job_content' => $val[5],
					'result' => $val[6],
					'status' => $val[7],
					'type' => $val[8],
					'main_param' => $val[9],
					'dirty' => false,
				);
				if ($val[0] > $max_id)
					$max_id = $val[0];
			}
			$cmd = array_merge($cmd, $tmp);
			log::write("append cmd max_id {$max_id}" . print_r($tmp, true));
		}
	}
	else
	{
		if (empty($execmd))
		{
			return 1;
		}
	}

	if (empty($execmd) && !empty($cmd))
	{
		$execmd[] = array_shift($cmd);
	}
	
	foreach($execmd as &$val)
	{
		if ($val['type'] == 1)
		{
			if (!isset($val['fd']))
			{
				$comand = $val['main_param'] ." ". $val['param'] . " 2>&1";
				$handle = popen($comand, 'rb');                     
				$val['fd'] = $handle;
				$val['dirty'] = true;
				$val['status'] = 3;
			}

			if(!feof($val['fd']))                            
			{                                                
				$read = fread($val['fd'], 1024);                
				$val['result'] .= $read;                           
				if (strlen($read) > 0)
				{
					$val['dirty'] = true;
				}
			}                                                
			else
			{
				$r = pclose($val['fd']);                                 
				if ($r != 0)
				{
					$val['status'] = 2;
				}
				else
				{
					$val['status'] = 1;
				}
				$val['dirty'] = true;
			}
		}
		else
		{
			$val['result'] = 'this type can not be support';
			$val['status'] = 2;
			$val['dirty'] = true;
		}
	}

	foreach($execmd as $key => &$val)
	{
		if ($val['dirty'])
		{
			$create->UpdateJob($val['id'], $val['status'], $val['result']);
			$val['dirty'] = false;
		}

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
	global $signal_flag;
	$pid = pcntl_fork(); // fork
	if ($pid < 0)
		exit;
	else if ($pid) // parent
		exit;
	else { // child

		$sid = posix_setsid();
		#chdir("/"); 
		#fclose(STDIN);
		#fclose(STDOUT);
		#fclose(STDERR);
		#$STDIN = fopen('/dev/null', 'r');
		#$STDOUT = fopen('log/out.log', 'wb');
		#$STDERR = fopen('log/error.log', 'wb');
		if ($sid < 0)
			exit;
		handler_init();
		while(1)
		{
			$ret = handler_process();
			usleep(200000);			
			if ($ret == 1)
				return;
		}
	}
	handler_final();
}

ini_set('display_errors', 0);
ini_set('error_log', 'log/sys.log');
daemon();
?>
