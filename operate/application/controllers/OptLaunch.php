<?php

class OptLaunch extends Controller {
	
	function index($id)
	{
		global $config;

		if(!isset($id))
		{
			log::write("you need set id", 'apache');
			return;
		}

		require_once(APP_DIR .'models/DBCtrl.php');

		$model = new DBCtrl;
		$model->Init();
		$job_model_arr = $model->GetJobModelListByModuleId($id);
		$module_list = $model->GetModuleByType(1);
		
		$template = $this->loadView('opt_launch');
		$template->set('config', $config);
		$template->set('job_model_arr', $job_model_arr);
		$template->set('username', $_SESSION['user_name']);
		$template->set('active', $id * 1000 + 1);
		$template->set('module',$module_list);
		$template->set('module_id', $id);
		$template->render();
	}
   	
   	function PostJob()
	{
		if (!isset($_REQUEST['JobModelParam']))
		{
			log::write("JobModelParam is not set", 'apache');
			header("Location: ". BASE_URL . "/main"); 
			return;
		}

		require_once(APP_DIR .'models/DBCtrl.php');
		$model = new DBCtrl;
		$model->Init();
		if ($_REQUEST['JobModelIsSave'])
		{
			$model->InsertJobModel($_REQUEST['JobModelModuleId'], $_REQUEST['JobModelParam'], $_REQUEST['JobModelJobContent']);
		}
		
		$model->InsertJob($_REQUEST['JobModelModuleId'], $_REQUEST['JobModelParam'], $_REQUEST['JobModelJobContent'], $_SESSION['user_id']);
		header("Location: ". BASE_URL . "/OptLaunch/index/{$_REQUEST['JobModelModuleId']}"); 
	}	

	function JobExec($id)
	{
		require_once(APP_DIR .'models/DBCtrl.php');

		$model = new DBCtrl;
		$model->Init();
		$result = $model->GetJobModel($id);
		if (!isset($result))
		{
			log::write("{$id} can not find in job model", 'apache');
			header("Location: ". BASE_URL . "/main"); 
			return;
		}
		$row = $result[0];
		$model->InsertJob($row[0], $row[1], $row[2], $_SESSION['user_id']);
		header("Location: ". BASE_URL . "/OptLaunch/index/{$row[0]}"); 
	}
}

?>
