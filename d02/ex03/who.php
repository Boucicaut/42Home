#!/usr/bin/php
<?php
	date_default_timezone_set("Europe/Paris");
	$filename = "/var/run/utmpx";
	$file = fopen($filename, 'r');

	while ($line = fread($file, 628))
	{
		$tmp = unpack("a256a/a4b/a32c/id/ie/If", $line);
		$array[$tmp['c']] = $tmp;
	}
	ksort($array);
	foreach($array as $j => $item)
	{
		if ($item['e'] == 7)
		{
			echo ($item['a']." ".$item['c']."  ");
			echo (date("M d H:i", $item['f']))."\n";
		}
	}
?>
