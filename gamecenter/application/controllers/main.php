<?php

class Main extends Controller {
	
	function index($para)
	{
		global $config;

		$model = new DataCtrl;
		$model->Init();
		$data = $model->HandlerGetIndex();
		
		$template = $this->loadView('index');
		$template->set('config', $config);
		$template->set('channel', $para['channel']);
		$template->set('AdHotGame', $data['AdHotGame']);
		$template->set('AdEditorRecommand', $data['AdHotGame']);
		$template->set('AdGameInfo', $data['AdGameInfo']);
		$template->set('HotGame', $data['HotGame']);
		$template->set('NewGame', $data['NewGame']);
		$template->render();
	}
   	
   	function hotGame($para)
	{
		global $config;

		$page = $_REQUEST['page'];
		$data = array();
		if (!isset($page)
		{
			$data['state'] = 1;
			$data['errmsg'] = 'page is not set';
			echo json_encode($data);
			return;
		}
		$model = new DataCtrl;
		$model->Init();
		$data = $model->HandlerGetMoreHotGame($page);
		$data['status'] = 0;
		echo json_encode($data);
	}	
   	
   	function newGame($para)
	{
		global $config;

		$page = $_REQUEST['page'];
		$data = array();
		if (!isset($page)
		{
			$data['state'] = 1;
			$data['errmsg'] = 'page is not set';
			echo json_encode($data);
			return;
		}
		$model = new DataCtrl;
		$model->Init();
		$data = $model->HandlerGetMoreHotGame($page);
		$data['status'] = 0;
		echo json_encode($data);
	}	
}

?>
