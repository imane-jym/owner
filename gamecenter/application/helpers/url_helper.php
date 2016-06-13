<?php

class Url_helper {

	function base_url()
	{
		global $config;
		return $config['base_url'];
	}
	
	function segment($seg)
	{
		if(!is_int($seg)) return false;
		
		$parts = explode('/', $_SERVER['REQUEST_URI']);
	    return isset($parts[$seg]) ? $parts[$seg] : false;
	}
	
	function arrayToSegment($arr)
	{
		$result = array();
		foreach($arr as $key => $value)
		{
			$result[] = $key;
			$result[] = $value;
		}
		return implode("/", $arr);
	}	

	function segmentsToArray($seg)
	{
		$segments = explode('/', $url);
		$result = array();
		for ($i = 0; $i < count($segments); $i += 2)
		{
			if (isset($segments[$i + 1]))
				$result[$segments[$i]] = $segments[$i + 1];
		}	
		return $result;
	}
}

?>
