<?php

class CDkey extends Controller {
	
	function index()
	{
		global $config;
		
		$util = new Util;
        require_once(APP_DIR . 'models/cdkey_model.php');

		//print_r($_POST);	
		$author = $_POST['author'];
		$channel = $_POST['channel'];
		$start_time = strtotime($_POST['start_time']);
	   	$end_time = strtotime($_POST['end_time']);	
		$limit_number = $_POST['limit_number'];
		$content = $_POST['content'];
		$prize = $_POST['prize'];
		$cdkey_number = $_POST['cdkey_number'];
		$server = $_POST['server'];
		
		if (!isset($author))
		{
			echo "author must be set";
			return;
		}

		if (!isset($channel))
		{
			echo 'channel must be set';
			return;
		}

		if (!isset($start_time))
		{
			echo 'start_time must be set';
			return;
		}
		
		if (!isset($end_time))
		{
			echo 'end_time must be set';
			return;
		}

		if (!isset($limit_number))
		{
			echo 'limit number must be set';
			return;
		}

		if (!isset($content))
		{
			echo 'content must be set';
			return;
		}

		if (!isset($prize))
		{
			echo 'prize must be set';
			return;
		}

		if (!isset($cdkey_number))
		{
			echo 'cdkey number must be set';
			return;
		}

		if (!isset($server))
		{
			echo 'server must be set';
			return;
		}
		if ($cdkey_number > 100000)
		{
			echo 'max cdkey number is 100k number';
			return;
		}

		$cdkey = new CDkeyModel;
		$addr = $config['operate_server_addr'][$server];
		$addr_arr = explode(',', $addr[1]);
		$cdkey->Init($addr_arr[0], $addr_arr[1], $addr_arr[2], $addr_arr[3]);
 		
		$batch_id = $cdkey->CreateBatch($channel, $start_time, $end_time, $limit_number, $content, time(NULL), $author, $prize);
		if ($batch_id == 0)
		{
			echo "create batch fail";
			return;
		}
		
		$arr_cdkey = array();	
		$number = 0;
		for ($i = 0; $i < $cdkey_number; $i++)
		{	
			$a =  $util->rand_str_create($batch_id, 6);
			if (in_array($a, $arr_cdkey))
			{
				$number++;	
			}
			else
			{
				array_push($arr_cdkey, $a);
			}
		}

		for ($i = 0; $i < count($arr_cdkey); $i++)
		{
			$res = $cdkey->InsertCDkey($arr_cdkey[$i], $batch_id, time(NULL), $author);
			if (!$res)
			{
				echo "insert cdkey fail";
				return;
			}
		}
		echo "<h3>insert success request number" . $cdkey_number . ", actual number " . ($cdkey_number - $number) . ". <br />batch is " . $batch_id . "</h3>";
	}

	function getlist()
	{
		global $config;

		$batch_id = $_POST['batch_id'];
		$server = $_POST['server'];
		if (!isset($batch_id))
		{
			echo 'batch_id must be set';
			return;
		}
		if (!isset($server))
		{
			echo 'server must be set';
			return;
		}
		
        require_once(APP_DIR . 'models/cdkey_model.php');
		$cdkey = new CDkeyModel;
		$addr = $config['operate_server_addr'][$server];
		$addr_arr = explode(',', $addr[1]);
		$cdkey->Init($addr_arr[0], $addr_arr[1], $addr_arr[2], $addr_arr[3]);

		$content = "cdkey,batch_id,status,channel,start_time,end_time,limit_number,batch_content\r\n";
		$res = $cdkey->GetCDkeyList($batch_id);
		foreach ($res as $val)
		{
			$content .= implode(',', $val);
			$content .= "\r\n";
		}
		$file = new Files;
		$file->download($content, 'cdkey.csv');
	}
}

?>
