<?php 

$config['base_url'] = ''; // Base URL including trailing slash (e.g. http://localhost/)

$config['default_controller'] = 'main'; // Default controller to load
$config['error_controller'] = 'error'; // Controller used for errors (e.g. 404, 500 etc)

$config['db_host'] = '172.16.1.149'; // Database host (e.g. localhost)
$config['db_name'] = 'card_operate'; // Database name
$config['db_username'] = 'imane'; // Database username
$config['db_password'] = 'imane'; // Database password

$config['login_user'] = 'imane'; //user name
$config['login_passwd'] = 'imane'; // user password

$config['upload_dir'] = APP_DIR . 'upload/';

$config['server_addr'] = array(
	'91_test_server' => array('91越狱测试服','launch_91s1','restart_91s1'),
	'temp_test_login' => array('临时测试登录服','launch_tl','restart_tl'),
	'temp_test_server' => array('临时测试游戏服','launch_ts1','restart_ts1'),
	'temp_test_res' => array('临时测试资源服','launch_tsr','restart_tsr'),
	'app_server' => array('app测试游戏服','launch_apps1','restart_apps1'),
	'91_server2' => array('91越狱二区', 'launch_91s2', 'restart_91s2'),
	'91_login' => array('91越狱登录服', 'launch_91l', 'restart_91l'),
	'91_res' => array('91越狱资源服', 'launch_91r', 'restart_91r'),
);

// params #res resourcefile 
$config['oper'] = array(
	'launch_91s1' => 'scp -r #res/config ubuntu@10.6.5.237:/data/91ioscard/ 2>&1 && echo "success"',
	'restart_91s1'=> 'ssh ubuntu@10.6.5.237 \'cd /data/91ioscard/shell && ./server_ctrl.sh -s gameserver -c restart && echo success\'',

	'launch_tl' => 'scp -r #res/config ubuntu@10.6.5.237:/data/temp_test 2>&1 && echo "success"',
	'restart_tl'=> 'ssh ubuntu@10.6.5.237 \'cd /data/temp_test/shell && ./server_ctrl.sh -s loginserver -c restart && echo success\'',

	'launch_ts1' => 'scp -r #res/config ubuntu@10.6.5.237:/data/temp_test 2>&1 && echo "success"',
	'restart_ts1'=> 'ssh ubuntu@10.6.5.237 \'cd /data/temp_test/shell && ./server_ctrl.sh -s gameserver -c restart && echo success\'',

	'launch_tsr' => 'scp -r #res/res/* ubuntu@10.6.3.239:/data/alipayResource 2>&1 && echo "success"',
	'restart_tsr'=> 'echo "no use"',

	'launch_apps1' => 'scp -r #res/config ubuntu@10.6.3.237:/data/app/ 2>&1 && echo "success"',
	'restart_apps1'=> 'ssh ubuntu@10.6.5.237 \'cd /data/app/shell && ./server_ctrl.sh -s gameserver -c restart && echo success\'',

	'launch_91s2' => 'scp -r #res/config ubuntu@10.6.3.138:/data/card/ 2>&1 && echo "success"',
	'restart_91s2'=> 'ssh ubuntu@10.6.3.138 \'cd /data/card/shell && ./server_ctrl.sh -s gameserver -c restart && echo success\'',

	'launch_91l' => 'scp -r #res/config ubuntu@10.6.1.195:/data/card/ 2>&1 && echo "success"',
	'restart_91l'=> 'ssh ubuntu@10.6.1.195 \'cd /data/card/shell && ./server_ctrl.sh -s loginserver -c restart && echo success\'',

	'launch_91r' => 'scp -r #res/res/* ubuntu@10.6.3.239:/data/91Resource/ 2>&1 && echo "success"',
	'restart_91r'=> 'echo "no use"',
);

$config['operate_server_addr'] = array(
	'inner_test' => array('斗宗内网测试服', '172.16.1.149,card_operate,imane,imane')
);
// ini_set("memory_limit", "512M");
// ini_set("upload_max_filesize", "30M"); //user script can not update 
// ini_set("post_max_size", "40M"); //user script can not update
?>
