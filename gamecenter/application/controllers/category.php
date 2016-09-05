<?php

class Category extends Controller {
	
	function index($para)
	{
		global $config;
		
		if (!isset($para['category_id']) && !is_numeric($para['category_id']))
		{
			Util::errorPage('404', 'category_id is not set');
			return;
		}
		$channel = 1;
		if (isset($para['channel']))
			$channel = $para['channel'];
		$model = new DataCtrl;
		$data = $model->HandlerGetMoreCategoryGame(0, $para['category_id']);
		//$channelInfo = $model->HandlerGetChannelInfo($channel);
		
		//var_dump($data);
		$template = $this->loadView('category');
		$template->set('config', $config);
		if ($channel != 1)
			$template->set('channel', $channel);
		$template->set('Category', $data);
		$template->set('CategoryId', $para['category_id']);
		//$template->set('ChannelInfo', $channelInfo);
		$template->render();
	}

	function categoryGame($para)
	{
		global $config;

		$page = $_REQUEST['page'];
		$category_id = $_REQUEST['category_id'];
		$data = array();
		if (!isset($page) && !is_numeric($page) && !isset($category_id) && !is_numeric($category_id))
		{
			Util::errorJson("1", 'page is not set');
			return;
		}
		$model = new DataCtrl;
		$data = $model->HandlerGetMoreCategoryGame($page, $category_id);
		//var_dump($data);
		$data['status'] = 0;
		echo json_encode($data);
	}
}

?>
