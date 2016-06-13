<?php

class Main extends Controller {
	
	function index()
	{
		global $config;

		require_once(APP_DIR .'models/DBCtrl.php');

		$model = new DBCtrl;
		$model->Init();
		$module_list = $model->GetModuleByType(1);
		
		$template = $this->loadView('job_list');
		$template->set('config', $config);
		$template->set('username', $_SESSION['user_name']);
		$template->set('active', 0);
		$template->set('module',$module_list);
		$template->render();
	}
    
	function GetResult($id)
	{
		require_once(APP_DIR .'models/DBCtrl.php');

		$model = new DBCtrl;
		$model->Init();
		$result = $model->GetJobContent($id);
		if (!isset($result))
		{
			return;
		}
		$row = $result[0];
		$row[0] = str_replace(PHP_EOL, "<br />", $row[0]);
		echo $row[0];
	}

	function GetJob()
	{
		require_once(APP_DIR .'models/DBCtrl.php');

		$model = new DBCtrl;
		$model->Init();
		$result = $model->GetJobList();
		if (!isset($result))
		{
			return;
		}

		foreach($result as &$val)
		{
			$val[3] = $model->to_datetime($val[3]);
		}
		echo json_encode($result);
	}
}

?>
