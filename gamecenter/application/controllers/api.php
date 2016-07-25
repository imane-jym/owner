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
		$model->ResetChannelCache();
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
   	
   	function getGameInfo()
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
		if (!isset($_REQUEST['gameId']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'gameId unvalid'));
			return;
		}

		$model = new DataCtrl;	
		$data = $model->GetAndSetGameInfoCache(array($_REQUEST['gameId']));
		echo json_encode(array('status' => 0, 'errmsg' => 'success', 'data' => $data[$_REQUEST['gameId']]));
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
		$model->ResetOnSaleCache($id['id']);
		$model->ResetGameCache($id['id']);
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
		$model->ResetOffSaleCache($id['id']);
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}	
}

?>
