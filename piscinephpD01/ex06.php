#!/usr/bin/php
<?php
	if ($argc < 2)
		exit();
	unset($argv[0]);
	foreach($argv as $i)
		$array[] = array_filter(explode(" ", $i));
	sort($array);
	foreach($array as $i)
		foreach($i as $j)
			echo $j . "\n";
?>
