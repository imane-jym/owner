<?php

class RedisCtrl {

    private $connection;

	public function Init()
	{
		global $config;
		$this->connection = new Redis();
		$this->connection->pconnect($config["redis_ip"], $config["redis_port"], 2.5);
	}

	public function AddPre(&$key, $pre, $type)
	{
		//var_dump($key, $pre, $type, "<br/>");
	    switch($type)
	    {
	        case "array":
	            foreach($key as $k => &$v)
	            {
	                $v = $pre . $v;
	            }
	        break;
	        case "aso_array":
				$result = array();
	            foreach($key as $k => $v)
                {
                    $result[$pre . $k] = $v;
                }
				$key = $result;
	        break;
	        default:
	            $key = $pre . $key;
	        break;
	    }
	}

	public function Delete($arr)
	{
	    global $config;
	    $this->AddPre($arr, $config["redis_pre"], "string");
		return $this->connection->delete($arr);
	}

	public function StringMGet($arr)
	{
	    global $config;
	    $this->AddPre($arr, $config["redis_pre"], "array");
		return $this->connection->mGet($arr);
	}

    public function StringMSet($aso_arr)
    {
    	global $config;
		//var_dump($aso_arr);
    	$this->AddPre($aso_arr, $config["redis_pre"], "aso_array");
        return $this->connection->mSet($aso_arr);
    }

	public function HashMGet($hName, $arr)
	{
	    global $config;
	    $this->AddPre($hName, $config["redis_pre"], "string");
		return $this->connection->hMGet($hName, $arr);
	}

    public function HashMSet($hName, $aso_arr)
    {
 		global $config;
	    $this->AddPre($hName, $config["redis_pre"], "string");
		return $this->connection->hMSet($hName, $aso_arr);
    }

	public function ListRPush($lName, $value)
	{
	    global $config;
	    $this->AddPre($lName, $config["redis_pre"], "string");
		return $this->connection->rPush($lName, $value);
	}

    public function ListRPop($lName)
    {
 		global $config;
	    $this->AddPre($lName, $config["redis_pre"], "string");
		return $this->connection->lPop($lName);
    }

    public function ListRange($lName, $start, $end)
    {
 		global $config;
	    $this->AddPre($lName, $config["redis_pre"], "string");
		return $this->connection->lRange($lName, $start, $end);
    }

	public function ZSetAdd($zName, $val, $score)
	{
	    global $config;
	    $this->AddPre($zName, $config["redis_pre"], "string");
		//var_dump($zName);
		return $this->connection->zAdd($zName, $score, $val);
	}

	public function ZSetDel($zName, $val)
	{
	    global $config;
	    $this->AddPre($zName, $config["redis_pre"], "string");
		return $this->connection->zRem($zName, $val);
	}

    public function ZSetRange($zName, $start, $end)
    {
 		global $config;
	    $this->AddPre($zName, $config["redis_pre"], "string");
		return $this->connection->zRange($zName, $start, $end);
    }

    public function ZSetRevRange($zName, $start, $end)
    {
 		global $config;
	    $this->AddPre($zName, $config["redis_pre"], "string");
		return $this->connection->zRevRange($zName, $start, $end);
    }
}

?>
