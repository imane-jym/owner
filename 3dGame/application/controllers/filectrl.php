<?php

class FileCtrl extends Controller {
	
	function upload()
	{
		$name = "";
		$file = new Files;
		$file->upload($name);
	}

	function download()
	{
		global $config;
		$file = new Files;
		$path = $config['upload_dir'] . $_REQUEST['userfile'];
		$file->downloadFile($path);
	}
}
?>
