<head>
<meta http-equiv="content-type" content="text/html;charset=utf-8">
</head>
<body>
<?php
error_reporting(E_ALL);

$version = $_REQUEST['v'];

$cmd = "cd /home/imane/WorkArea/card/trunk/server/shell/ && ./client_res.sh $version 2>&1" ;
$login = "ssh imane@172.16.1.149 '$cmd'";

/* Add redirection so we can get stderr. */
$handle = popen($login, 'rb');
while(!feof($handle))
{
	$read = fread($handle, 1024);
	echo $read;
}
pclose($handle);
?>
</body>
