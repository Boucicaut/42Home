#!/usr/bin/php
<?php
	if ($argc != 2)
		exit();
	$array = explode(' ', $argv[1]);
	foreach($array as $sub)
		if ($sub != '')
			$str .= $sub . ' ';
	echo trim($str) . "\n";
?>
