<?php

class RedisCtrl {

    private $connection;

	public function Init()
	{
		global $config;
		$connection = new Redis();
		$connection->pconnect($config["redis_ip"], $config["redis_port"], 2.5);
	}

	public function AddPre(&$key, $pre, $type)
	{
	    switch($type)
	    {
	        case "array":
	            foreach($key as $k => &$v)
	            {
	                $v = $pre . $v;
	            }
	        break;
	        case "aso_array":
	            foreach($key as $k => $v)
                {
                    $key[$pre . $k] = $v;
					unset($key[$k]);
                }
	        break;
	        default:
	            $key = $pre . $key;
	        break;
	    }
	}

	public function Delete($arr)
	{
	    global $config;
	    $this->AddPre($arr, $config["redis_pre"], "array");
		return $connection->delete($arr);
	}

	public function StringMGet($arr)
	{
	    global $config;
	    $this->AddPre($arr, $config["redis_pre"], "array");
		return $connection->mGet($arr);
	}

    public function StringMSet($aso_arr)
    {
    	global $config;
    	$this->AddPre($arr, $config["redis_pre"], "aso_array");
        return $connection->mSet($aso_arr);
    }

	public function HashMGet($hName, $arr)
	{
	    global $config;
	    $this->AddPre($hName, $config["redis_pre"], "string");
		return $connection->hMGet($hName, $arr);
	}

    public function HashMSet($hName, $aso_arr)
    {
 		global $config;
	    $this->AddPre($hName, $config["redis_pre"], "string");
		return $connection->hMSet($hName, $aso_arr);
    }

	public function ListRPush($lName, $value)
	{
	    global $config;
	    $this->AddPre($lName, $config["redis_pre"], "string");
		return $connection->rPush($lName, $value);
	}

    public function ListRPop($lName)
    {
 		global $config;
	    $this->AddPre($lName, $config["redis_pre"], "string");
		return $connection->lPop($lName);
    }

    public function ListRange($lName, $start, $end)
    {
 		global $config;
	    $this->AddPre($lName, $config["redis_pre"], "string");
		return $connection->lRange($lName, $start, $end);
    }

	public function ZSetAdd($zName, $val, $score)
	{
	    global $config;
	    $this->AddPre($zName, $config["redis_pre"], "string");
		return $connection->zAdd($zName, $score, $val);
	}

	public function ZSetDel($zName, $val)
	{
	    global $config;
	    $this->AddPre($zName, $config["redis_pre"], "string");
		return $connection->zRem($zName, $val);
	}

    public function ZSetRange($zName, $start, $end)
    {
 		global $config;
	    $this->AddPre($zName, $config["redis_pre"], "string");
		return $connection->zRange($zName, $start, $end);
    }

    public function ZSetRevRange($zName, $start, $end)
    {
 		global $config;
	    $this->AddPre($zName, $config["redis_pre"], "string");
		return $connection->zRevRange($zName, $start, $end);
    }
}

?>
