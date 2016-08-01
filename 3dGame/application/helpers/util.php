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
}

?>
