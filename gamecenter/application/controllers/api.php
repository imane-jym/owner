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
   	
   	function UpsertGame()
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
		if (!is_numeric($_REQUEST['game_id']) || !is_numeric($_REQUEST['create_time']) || !is_numeric($_REQUEST['onsale_time']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'game_id create_time or onsale_time unvalid'));
			return;
		}
		if (!is_numeric($_REQUEST['status']) || !is_numeric($_REQUEST['is_login']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'status is_login unvalid'));
			return;
		}

		$model = new DataCtrl;	
		$model->UpsertGame($_REQUEST);
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}	
   	
   	function UpsertCategory()
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
		if (!is_numeric($_REQUEST['category_id']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'category_id unvalid'));
			return;
		}

		$model = new DataCtrl;	
		$model->UpsertCategory($_REQUEST);
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}	

   	function UpsertAd()
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
		foreach($_REQUEST as $k => $v)
		{
			if (!is_numeric($v['hot_id']))
			{
				echo json_encode(array('status' => -1, 'errmsg' => 'game_id create_time or onsale_time unvalid'));
				return;
			}
		}

		$model = new DataCtrl;	
		$model->UpsertGame($_REQUEST);
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}	

   	function UpsertChannel()
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
		if (!is_numeric($v['channel_id']))
		{
			echo json_encode(array('status' => -1, 'errmsg' => 'channel_id unvalid'));
			return;
		}

		$model = new DataCtrl;	
		$model->UpsertChannel($_REQUEST);
		echo json_encode(array('status' => 0, 'errmsg' => 'success'));
	}	
   	
   	
}

?>
