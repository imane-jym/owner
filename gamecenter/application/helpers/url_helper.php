<?php

class Url_helper {

	public static function base_url()
	{
		global $config;
		return $config['base_url'];
	}
	
	public static function segment($seg)
	{
		if(!is_int($seg)) return false;
		
		$parts = explode('/', $_SERVER['REQUEST_URI']);
	    return isset($parts[$seg]) ? $parts[$seg] : false;
	}
	
	public static function arrayToSegment($arr)
	{
		$result = array();
		foreach($arr as $key => $value)
		{
			$result[] = $key;
			$result[] = $value;
		}
		return implode("/", $result);
	}	

	public static function segmentsToArray($seg)
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

	public static function urlAddPara($url, $array)
	{
		$data = parse_url($url);
		$para = $data['query'];
		if (isset($para) && !empty($array))
		{
			$para .= "&" . http_build_query($array);
		}
		if (!empty($para))
			$para = "?" . $para;
		return $data['scheme'] . "://" . (isset($data['user']) ? ($data['user'] . ":" . $data['pass'] . "@" ) : "") . $data['host'] . $data['path'] . $para . (isset($data['anchor']) ? "#" . $data['anchor'] : "");
	}
}

?>
