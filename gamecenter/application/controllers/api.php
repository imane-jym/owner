<?php

class Api extends Controller {
	
	function flushAllCache()
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			return -1;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			return -1;
		}

		$model = new DataCtrl;	
		$model->ResetAdCache();
		$model->ResetCategoryCache();
		$model->ResetNewGameCache();
	}
   	
   	function onSaleGame($id)
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			return -1;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			return -1;
		}

		$model = new DataCtrl;	
		$model->ResetOnSaleCache($id);
		$model->ResetGameCache($id);
	}	
   	
   	function offSaleGame($id)
	{
		global $config;
		if (!isset($_REQUEST['token']))
		{
			return -1;
		}
		if ($_REQUEST['token'] != $config['secure_key'])
		{
			return -1;
		}

		$model = new DataCtrl;	
		$model->ResetOffSaleCache($id);
	}	
}

?>
