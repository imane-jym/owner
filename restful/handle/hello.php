<?

require_once ("rest_client.php");
require_once ("Pest.php");

$client = new RestClient();

//$res = $client->get('http://10.0.0.178/test/index.php/2123?para1=22&para2=33');
//echo $res;
//
//$res = $client->post('http://10.0.0.178/test/index.php/2123', array('para1'=>22, 'para2'=>33));
//echo $res;
//
//$res = $client->post('http://10.0.0.178/test/index.php/2123', json_encode(array('para1'=>22, 'para2'=>33)));
//echo $res;

//$res = $client->post('http://10.0.0.178/test/index.php/2123', 'para1=22&para2=33');
//echo $res;

//$res = $client->put('http://10.0.0.178/test/index.php/2123', '2233');
//echo $res;
//
//$res = $client->put('http://10.0.0.178/test/index.php/2123', 'para1=22&para2=33');
//echo $res;

//$res = $client->delete('http://10.0.0.178/test/index.php/2123?para1=22&para2=33');
//echo $res;

$pest = new Pest('');

//$res = $pest->get('http://10.0.0.178/test/index.php/2123?para1=22&para2=33');
//echo $res;
//
//$res = $pest->post('http://10.0.0.178/test/index.php/2123', array('para1'=>22, 'para2'=>33));
//echo $res;
//
//$res = $pest->post('http://10.0.0.178/test/index.php/2123', 'para1=22&para2=33');
//echo $res;
//
//$res = $pest->put('http://10.0.0.178/test/index.php/2123', '2233');
//echo $res;

$res = $pest->put('http://10.0.0.178/test/index.php/2123', array('para1'=>22, 'para2'=>33));
echo $res;

$res = $pest->delete('http://10.0.0.178/test/index.php/2123?para1=22&para2=33');
echo $res;
