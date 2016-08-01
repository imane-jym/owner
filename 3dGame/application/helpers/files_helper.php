<?php

class Files{

	function upload(&$name)
	{
		global $config;
		$uploaddir = $config['upload_dir'];
		$uploadfile = $uploaddir . basename($_FILES['userfile']['name']);

		echo '<pre>';
		if (move_uploaded_file($_FILES['userfile']['tmp_name'], $uploadfile)) {
			    echo "File is valid, and was successfully uploaded.\n";
		} else {
			    echo "Possible file upload attack!\n";
		}

		echo 'Here is some more debugging info:';
		print_r($_FILES);
		$name = $uploadfile;
		print "</pre>";
	}

	function decompress($file)
	{
		$extension = strstr($file, '.');
		$content = '';
		if ($extension == ".tar.gz")
		{
			$cmd = 'cd application/upload/ &&  tar -xvf ' . $file . '&& unlink ' . $file;
			$handle = popen($cmd, 'rb');                                                          
			while(!feof($handle))                                          
			{                                                                  
				$read = fread($handle, 1024);
				$content .= $read;
			}
			pclose($handle);
			$content = str_replace("\n", '<br />', $content);
		}
		echo $content;
	}

	function download($content, $file)
	{
		header('Content-Description: File Transfer');

		header('Content-Type: application/octet-stream');
		header('Content-Disposition: attachment; filename="' . $file . '"');
		header('Content-Transfer-Encoding: binary');
		header('Expires: 0');
		header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
		header('Pragma: public');
		header('Content-Length: ' . strlen($content));
		echo $content;
	}

	function downloadFile($filename)
	{
		if (!file_exists($filename))
			return;

		header('Content-Description: File Transfer');
		header('Content-Type: application/octet-stream');
		header('Content-Disposition: attachment; filename="' . basename($filename) . '"');
		header('Content-Transfer-Encoding: binary');
		header('Expires: 0');
		header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
		header('Pragma: public');
		header('Content-Length: ' . filesize($filename));
		ob_clean();
		flush();
		readfile($filename);
	}
}

?>
