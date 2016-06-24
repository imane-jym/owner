<?php

class Error extends Controller {
	
	function index()
	{
		//global $config;
		//$template = $this->loadView('page404');
		//$template->set('config', $config);
		//$template->render();
		echo '<h1>404 Error</h1>';
		echo '<p>Looks like this page doesn\'t exist</p>';
	}
	
	function error404()
	{
		echo '<h1>404 Error</h1>';
		echo '<p>Looks like this page doesn\'t exist</p>';
	}
}

?>
