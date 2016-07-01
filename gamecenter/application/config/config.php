<?php 

$config['base_url'] = 'http://172.16.0.89/test/'; // Base URL including trailing slash (e.g. http://localhost/)

$config['default_controller'] = 'main'; // Default controller to load
$config['error_controller'] = 'error'; // Controller used for errors (e.g. 404, 500 etc)

$config['db_host'] = '127.0.0.1'; // Database host (e.g. localhost)
$config['db_name'] = 'game_center'; // Database name
$config['db_username'] = 'game'; // Database username
$config['db_password'] = '123456'; // Database password

$config['redis_ip'] = '127.0.0.1'; //redis ip, this redis is used for cache
$config['redis_port'] = '6379'; // redis port
$config['redis_pre'] = 'CenterGame';

$config['login_user'] = 'imane'; //user name http auth use
$config['login_passwd'] = 'imane'; // user password http auth use
$config['login_enter'] = 'http://login.jvziyouxi.com/auth'; // user password http auth use

$config['secure_key'] = 'asEg38s3l94'; //backport secure key

define('LOG_PATH', ROOT_DIR .'log/');
define('LOG_FILE_SIZE', 10485760); // 10mb
define('LOG_DATA_PATH', ROOT_DIR .'log/');
define('LOG_DATA_FILE_SIZE', 10485760); // 10mb
define('DS', DIRECTORY_SEPARATOR);
define('PARA_ARRAY', 1);

define('BASE_URL', $config['base_url']);


// ini_set("memory_limit", "512M");
// ini_set("upload_max_filesize", "30M"); //user script can not update 
// ini_set("post_max_size", "40M"); //user script can not update
?>
