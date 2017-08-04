<?php
$address="10.0.0.23";
$service_port=5555;

function hexdump($str)
{
    printf("\n");
    for($i = 0; $i < strlen($str); $i++)
    {
        printf("%x ", ord($str[$i]));
    }
}

error_reporting(E_ALL);

echo "<h2>TCP/IP Connection</h2>\n";

/* Create a TCP/IP socket. */
$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket === false) {
    echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";
} else {
    echo "OK.\n";
}

echo "Attempting to connect to '$address' on port '$service_port'...";
$result = socket_connect($socket, $address, $service_port);
if ($result === false) {
    echo "socket_connect() failed.\nReason: ($result) " . socket_strerror(socket_last_error($socket)) . "\n";
} else {
    echo "OK.\n";
}

$out = '';

$cmd = 5;
$accountid = "test";
$pwd = "123";
$version = "1";
$len = strlen($pwd) + strlen($accountid) + strlen($version) + 3 + 4;
$in = pack("S2",$len, $cmd);
$in .= $accountid .chr(0). $pwd .chr(0) . $version . chr(0);

echo "Sending HEAD request...";
socket_write($socket, $in, strlen($in));
echo "OK.\n";

$cmd = 0x1c << 1 | 0x1;
$len = 4 + 8;
$in = pack("S2L2",$len, $cmd, 1, 1);

echo "Sending HEAD request...";
socket_write($socket, $in, strlen($in));

echo "Reading response:\n\n";
while ($tmp = socket_read($socket, 2048)) {
    $out .= $tmp;
    echo "====\n";
    //$abc = unpack("n", $out);
    //print_r($abc); 
    //$out = substr($out, 2);
    while (strlen($out) >= 4)
    {
        $apppacket = unpack("slen/scmd",$out);
        print_r($apppacket);
        if (strlen($out) >= $apppacket['len'])
        {
            $pkg1 = substr($out, 0, $apppacket['len']);
            hexdump($pkg1);
            $out = substr($out, $apppacket['len']);
            echo "\n";
        }
        else
        {
            break;
        }
    }
}

echo "Closing socket...";
socket_close($socket);
echo "OK.\n\n";
?>
