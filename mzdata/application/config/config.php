<?php 

//$config['base_url'] = 'http://172.16.0.89/opt'; // Base URL including trailing slash (e.g. http://localhost/)
//
//$config['default_controller'] = 'main'; // Default controller to load
//$config['error_controller'] = 'error'; // Controller used for errors (e.g. 404, 500 etc)

$config['db_host'] = '172.16.0.89'; // Database host (e.g. localhost)
$config['db_name'] = 'login'; // Database name
$config['db_username'] = '3d'; // Database username
$config['db_password'] = '123456'; // Database password

$config['mz_stat_url'] = 'http://www.baidu.com';
$config['mz_app_id'] = 'test';
$config['mz_app_key'] = 'dsdfd';
$config['mz_check_key'] = '111111';
//$config['login_user'] = 'imane'; //user name http auth use
//$config['login_passwd'] = 'imane'; // user password http auth use

define('LOG_PATH', ROOT_DIR .'log/');
define('LOG_FILE_SIZE', 10485760); // 10mb
define('LOG_DATA_PATH', ROOT_DIR .'log/');
define('LOG_DATA_FILE_SIZE', 10485760); // 10mb
define('DS', DIRECTORY_SEPARATOR);

//define('BASE_URL', $config['base_url']);

// ini_set("memory_limit", "512M");
// ini_set("upload_max_filesize", "30M"); //user script can not update 
// ini_set("post_max_size", "40M"); //user script can not update
?>
