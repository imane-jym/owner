<?php

class Serverctrl extends Controller {
	
	function index()
	{
		global $config;
		
		//print_r($_POST);	
		if (!isset($_POST['res']))
		{
			echo "res file can not be chosen";
			return;
		}

		if (!isset($_POST['oper']))
		{
			echo 'oper can not be set';
			return;
		}
		
		$cmd = $config['oper'][$_POST['oper']];
		if (!isset($cmd))
		{
			echo 'can not find function corresponding bash script';
			return;
		}
		$cmd = str_replace('#res', APP_DIR . 'upload/' . $_POST['res'], $cmd);
		//echo $cmd;

		/* Add redirection so we can get stderr. */                                             
		$content = '';
		$handle = popen($cmd, 'rb');                                                          
		while(!feof($handle))                                                                   
		{                                                                                       
			$read = fread($handle, 1024);                                                       
			$content .= $read;                                                                         
		}                                                                                       
		pclose($handle);                                                                        
		$content = str_replace("\n", '<br />', $content);
		echo $content;
	}

}
?>
