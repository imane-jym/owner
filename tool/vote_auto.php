<?php
//function request_by_other($remote_server, $post_string)
//{
//	$context = array(
//		'http' => array(
//			'method' => 'POST',
//			'header' => 'Content-type: application/x-www-form-urlencoded' .
//						'\r\n'.'User-Agent : ' .
//						'\r\n'.'Content-length:' . strlen($post_string) + 8,
//			'content' => $post_string)
//			);
//	$stream_context = stream_context_create($context);
//	$data = file_get_contents($remote_server, false, $stream_context);
//	return $data;
//}

function request_by_curl($remote_server, $post_string)
{
    $header= array(
		'Connection: keep-alive'
		,'Origin: http://www.forbeschina.com'
		,'X-Requested-With: XMLHttpRequest'
		,'User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.97 Safari/537.11'
		,'Accept: */*'
		,'Referer: http://www.forbeschina.com/subject/2012under30/'
		,'Accept-Encoding: gzip,deflate,sdch'
		,'Accept-Language: zh-CN,zh;q=0.8'
		,'Accept-Charset: GBK,utf-8;q=0.7,*;q=0.3'
		,'Cookie: under30cookie=1"');
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $remote_server);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $post_string);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $header); 
    curl_setopt($ch, CURLOPT_POST, true); 
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    $data = curl_exec($ch);
    curl_close($ch);
    return $data;
}


$str = request_by_curl("http://www.forbeschina.com/subject/2012under30/vote.php","id=51");
echo $str;
//$str = request_by_other("http://www.forbeschina.com/subject/2012under30/showcans.php","key=尹庆&type=0&order=id&page=1");
//echo $str;
//$str = request_by_other("http://www.forbeschina.com/subject/2012under30/showvote.php","");
//echo $str;
//$str = request_by_curl("http://10.0.0.178/test.php","id=51");
//var_dump($str);
?>
