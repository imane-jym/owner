<?php

class Util{

	function rand_str_create($pre, $number)
	{
		$a = '0123456789abcdefghijklmnopqrstuvwsyz';	
		$res = '';
		for ($i = 0; $i < $number; $i++)
		{
			$r = rand(0, strlen($a) - 1);
			$res .= $a[$r];
		}
		return $pre . $res;
	}

	static function prehook($controller, $action, $segment)
	{
		//var_dump($controller, $action, $segment);
		//var_dump($_SESSION);
		//if ($controller != "login")
		//{
		//	if (!isset($_SESSION['user_id']))
		//	{
		//		header("Location: ". BASE_URL . "/login"); 
		//		exit;
		//	}
		//}
		return 0;
	}

	static function afterhook($controller, $action, $segment)
	{
	}

	static function errorPage($title, $msg)
	{
		echo "<h1>$title</h1>";
		echo "<p>$msg</p>";
	}

	static function errorJson($state, $msg)
	{
		$data = array();
		$data['state'] = $state;
		$data['errmsg'] = $msg;
		echo json_encode($data);
	}
}

?>
