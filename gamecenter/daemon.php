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

function handler_init()
{
	$create = new DBCtrl;
	$create->Init();
	$create->CreateInitTable();
}

ini_set('display_errors', 0);
ini_set('error_log', 'log/sys.log');
handler_init();
?>
