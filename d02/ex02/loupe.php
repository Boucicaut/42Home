#!/usr/bin/php
<?php
if ($argc < 2 || !file_exists($argv[1]))
	exit();
$file = fopen($argv[1], 'r');
while ($file && !feof($file))
	$line .= fgets($file);

$line = preg_replace_callback("/(<[Aa] )(.*?)>(.*)(<\/[Aa]>)/s", function($matches) {
echo "1\n";
print_r($matches);
	$matches[0] = preg_replace_callback('/( title=)(.*?)(<)/mi', function($matches) {
echo "2\n";
print_r($matches);
		return ($matches[1].strtoupper($matches[2]).$matches[3]);
	}, $matches[0]);
	$matches[0] = preg_replace_callback("/(>)(.*?)(<)/si", function($matches) {
echo "3\n";
print_r($matches);
		return ($matches[1].strtoupper($matches[2]).$matches[3]);
	}, $matches[0]);
	return ($matches[0]);
}, $line);
echo $line;
?>
