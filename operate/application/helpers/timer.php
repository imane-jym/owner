<?php

class Timer{

	public $map_time = array();	

	function Init()
	{
		return false;
	}

	function registerTimer($key, $time)
	{
		$this->map_time[$key] = array('end_time' => time(NULL) + $time,
								'interval' => $time);
	}

	function deleteTimer($key)
	{
		unset($this->map_time[$key]);
	}

	function IsArriveTimer($key, $reset)
	{
		if (array_key_exists($key, $this->map_time))
		{
			$now = time(NULL);
			if ($this->map_time[$key]['end_time'] < $now)
			{
				if ($reset)
					$this->map_time[$key]['end_time'] += $this->map_time[$key]['interval'];
				return true;
			}
		}
		return false;
	}
}

?>
