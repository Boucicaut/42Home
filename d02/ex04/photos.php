#!/usr/bin/php
<?php
function page_html($url)
{
	$stream = curl_init($url);
	curl_setopt($stream, CURLOPT_RETURNTRANSFER, true);
	$data = curl_exec($stream);
	curl_close($stream);
	return ($data);
}
function find_img($data)
{
	preg_match_all('/(<img[^>].*src=")https?:\/\/.*?"/i', $data, $matches);
	foreach($matches as $j => $item)
	{
		foreach ($item as $j => $bal)
		{
			preg_match('/https?:\/\/.*?(?=")/i', $bal, $link);
			if (!empty($link))
				$res[] = $link;
		}
	}
	return ($res);
}
function setup_dir($url)
{
	$dirname = preg_replace('/^https?:\/\//', "", $url);
	if ((file_exists($dirname) || is_dir($dirname)))
		exit();
	mkdir($dirname);
	return ($dirname);
}
function img_name($img)
{
	foreach($img as $j => $item)
		$img[$j][1] = preg_replace('/(.*\/)/', "", $item[0]);
	return ($img);
}
function get_img($img, $dirname, $url)
{
	foreach($img as $j => $item)
	{
		$stream = curl_init($item[0]);
		curl_setopt($stream, CURLOPT_HEADER, false);
		curl_setopt($stream, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($stream, CURLOPT_BINARYTRANSFER, true);
		$data = curl_exec($stream);
		curl_close($stream);
		$file = fopen($dirname."/".$item[1], 'w');
		fwrite($file, $data);
		fclose($file);
	}
}

	if ($argc < 2 || (filter_var($argv[1], FILTER_VALIDATE_URL) === FALSE))
		exit();
	$url = $argv[1];
	$data = page_html($url);
	if (!empty($data))
		$img = find_img($data);
	if (!empty($img))
	{
		$dirname = setup_dir($url);
		$img = img_name($img);
	}
	get_img($img, $dirname, $url);
?>
