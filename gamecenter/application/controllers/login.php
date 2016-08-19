<?php

class Login extends Controller {
	
	function index()
	{
		global $config;
		
		$template = $this->loadView('login');
		$template->set('config', $config);
		$template->render();
	}

	function dologin()
	{
		global $config;
		require_once(APP_DIR .'models/DBCtrl.php');

		$model = new DBCtrl;
		$model->Init();
		$ret = $model->GetUserAuth($_REQUEST['username'], $_REQUEST['password']);

		#var_dump($_REQUEST);
		#var_dump($ret);
		if (isset($ret))
		{
			$row = $ret[0];
			$_SESSION['user_id'] = $row[0];
			$_SESSION['user_name'] = $row[1];
			$_SESSION['admin'] = $row[2];
			header("Location: ". BASE_URL . "/{$config['default_controller']}");
			return;
		}
	}

	function logout()
	{
		unset($_SESSION['user_id']);
		header("Location: ". BASE_URL . "/login");
	}
}

?>
