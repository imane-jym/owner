<?php

class DataOpt extends Controller {
	
	function GetJobList()
	{
		$model = new DBctrl;	
		$model->Init();
		echo json_encode($model->GetJobList());
	}
   	
   	function GetJobContent($id)
	{
		$model = new DBctrl;
		$model->Init();
		echo json_encode($model->GetJobContent());
	}	
}

?>
