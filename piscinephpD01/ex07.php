#!/usr/bin/php
<?php
	unset($argv[0]);
	foreach($argv as $i)
	{
		$array = array_filter(explode(" ", $i));
		foreach($array as $j)
			$res[] = $j;
	}
	$tmp = $res[0];
	$res[0] = $res[$argc - 2];
	$res[$argc - 2] = $tmp;
print_r($res);
	foreach($res as $j => $i)
	{
		if ($j > 0 && $j != $argc - 1)
			echo " ";
		echo "$i";
	}
?>
