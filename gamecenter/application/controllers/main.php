<?php

class Main extends Controller {
	
	function index($para)
	{
		global $config;

		$model = new DataCtrl;
		$channel = 1;
		if (isset($para['channel']))
			$channel = $para['channel'];
		$data = $model->HandlerGetIndex($channel);
		
		//var_dump($data);
		$template = $this->loadView('index');
		$template->set('config', $config);
		if ($channel != 1)
			$template->set('channel', $channel);
		$template->set('AdHotGame', $data['AdHotGame']);
		$template->set('AdEditorRecommand', $data['AdEditorRecommand']);
		$template->set('AdGameInfo', $data['AdGameInfo']);
		$template->set('HotGame', $data['HotGame']);
		$template->set('NewGame', $data['NewGame']);
		$template->set('Category', $data['Category']);
		$template->set('ChannelInfo', $data['ChannelInfo']);
		$template->render();
	}
   	
   	function hotGame($para)
	{
		global $config;

		$page = $_REQUEST['page'];
		$data = array();
		if (!isset($page) && !is_numeric($page))
		{
			Util::errorJson("1", 'page is not set');
			return;
		}
		$model = new DataCtrl;
		$data = $model->HandlerGetMoreHotGame($page);
		$data['status'] = 0;
		echo json_encode($data);
	}	
   	
   	function newGame($para)
	{
		global $config;

		$page = $_REQUEST['page'];
		$data = array();
		if (!isset($page) && !is_numeric($page))
		{
			Util::errorJson("1", 'page is not set');
			return;
		}
		$model = new DataCtrl;
		$data = $model->HandlerGetMoreNewGame($page);
		$data['status'] = 0;
		echo json_encode($data);
	}	
}

?>
