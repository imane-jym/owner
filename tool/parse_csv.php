#!/usr/bin/php5
<?php
function cmp($a, $b) {
	if ($a['max'] == $b['max']) {
		return 0;
	}
	return ($a['max'] < $b['max']) ? -1 : 1;
}

$result = array();
if (($handle = fopen("../handle_data", "r")) !== FALSE) {
	while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
		$key = $data[5];
		if (!isset($result[$key]['min']))
			$result[$key]['min'] = $data[6];
		if (!isset($result[$key]['max']))
			$result[$key]['max'] = $data[6];
		if (!isset($result[$key]['total']))
			$result[$key]['total'] = 0;
		if (!isset($result[$key]['count']))
			$result[$key]['count'] = 0;

		if ($data[6] < $result[$key]['min'])
			$result[$key]['min'] = $data[6];
		if ($data[6] > $result[$key]['max'])
			$result[$key]['max'] = $data[6];
		$result[$key]['total'] += $data[6];
		$result[$key]['count']++;
	}
	fclose($handle);
}

uasort($result, 'cmp');
foreach($result as $key => $val)
{
	echo "$key, min ,". $val['min'] . ", max ," . $val['max'] . ", avg ," . round($val['total'] / $val['count'], 2) . ", count ," . $val['count'] . "\n";
}
?>
