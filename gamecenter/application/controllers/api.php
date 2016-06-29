<?php

class Api extends Controller {
	
	function flushAllCache()
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'token unvalid'));
			return;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'token unvalid'));
			return;
		}

		$model = new DataCtrl;	
		$model->ResetAdCache();
		$model->ResetCategoryCache();
		$model->ResetNewGameCache();
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}

   	function onFlushChannel()
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'token unvalid'));
			return;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'token unvalid'));
			return;
		}

		$model = new DataCtrl;	
		$model->ResetChannelCache();
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}	
   	
   	
   	function onSaleGame($id)
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'token unvalid'));
			return;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'token unvalid'));
			return;
		}

		$model = new DataCtrl;	
		$model->ResetOnSaleCache($id);
		$model->ResetGameCache($id);
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}	
   	
   	function offSaleGame($id)
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'token unvalid'));
			return;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'token unvalid'));
			return;
		}

		$model = new DataCtrl;	
		$model->ResetOffSaleCache($id);
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}	
}

?>
