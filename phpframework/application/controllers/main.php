<?php

class Main extends Controller {
	
	function index()
	{
		global $config;
		if ($handle = opendir(APP_DIR . 'upload')) {
			while (false !== ($entry = readdir($handle))) {
				if ($entry != "." && $entry != "..") {
					$arr_res[] = $entry;
				}
			}
			closedir($handle);
		}
		
		sort($arr_res);
		$template = $this->loadView('main_view');
		$template->set('res', $arr_res);
		$template->set('serveraddr', $config['server_addr']);
		$template->set('operate_server_addr', $config['operate_server_addr']);
		$template->render();
	}
    
}

?>
