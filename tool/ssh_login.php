<?php
error_reporting(E_ALL);

$cmd = "cd ~imane/WorkArea/card/Resource/Config/ && svn up 2>&1" ;
$login = "ssh imane@10.0.0.178 '$cmd'";

/* Add redirection so we can get stderr. */
$handle = popen($login, 'rb');
while(!feof($handle))
{
	$read = fread($handle, 1024);
	echo $read;
}
#$handle = popen($cmd, 'rb');
pclose($handle);
?>
