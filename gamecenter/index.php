<?php
/*
 * PIP v0.5.3
 */

//Start the Session
session_start(); 

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
require_once(APP_DIR .'helpers/log.class.php');

require_once(APP_DIR .'helpers/redis.php');
require_once(APP_DIR .'models/DBCtrl.php');
require_once(APP_DIR .'models/DataCtrl.php');

pip();
?>
