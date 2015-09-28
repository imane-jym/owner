<?php

class FileCtrl extends Controller {
	
	function upload()
	{
		$file = new Files;
		$file->upload($name);
		$file->decompress($name);
	}
}
?>
