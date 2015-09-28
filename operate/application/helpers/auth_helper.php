<?php

class Auth {
	
	function Authenticate()
	{
		global $config;
		if (isset($_SESSION['login_user']))
		{
			return;
		}
		else
		{
			if (isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW']) && $_SERVER['PHP_AUTH_USER'] == $config['login_user'] && $_SERVER['PHP_AUTH_PW'] == $config['login_passwd'])
			{
				$_SESSION['login_user'] = $_SERVER['PHP_AUTH_USER'];
				unset($_SERVER['PHP_AUTH_USER']);
				unset($_SERVER['PHP_AUTH_PW']);
				return;
			}
			else
			{
				header('WWW-Authenticate: Basic realm="Please enter your account"');
				header('HTTP/1.0 401 Unauthorized');
				echo 'Account or password error. Please login first';
				exit;
			}
		}
	}
}
?>
