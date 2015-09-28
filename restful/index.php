<?php
require_once("handle/Toro.php");

class base
{
	function get($para)
	{
		echo $para;
		var_dump($_GET);
		var_dump($_SERVER);
	}
	function post($para)
	{
		echo $para;
		print_r($_POST);
		var_dump($_SERVER);
		echo file_get_contents("php://input");
	}
	function put($para)
	{
		//$_POST 无法获取参数, 可以通过raw request body 获取
		echo $para;
		var_dump($_SERVER);
		echo file_get_contents("php://input");
	}
	function delete($para)
	{
		// 通过url 获取数据, $_GET
		echo $para;
		var_dump($_GET);
		var_dump($_SERVER);
	}
}

Toro::serve(array(
	"/([0-9]+)" => "base"
	));
?>
