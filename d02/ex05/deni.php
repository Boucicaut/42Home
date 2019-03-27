#!/usr/bin/php
<?php
    if ($argc != 3)
        exit();
    if (!file_exists($argv[1]))
        exit();
	$file = fopen($argv[1], 'r');
    while ($file && !feof($file))
        $line[] = explode(";", fgets($file));
	fclose($file);

    $array = $line[0];
    unset($line[0]);

    if (($index = array_search($argv[2], $array)) === false)
        exit();

	foreach ($array as $k => $item)
	{
		foreach ($line as $j)
		{
			if (isset($j[$index]))
				$tmp[trim($j[$index])] = trim($j[$k]);
        }
		$$item = $tmp;
    }

	$file = fopen("php://stdin", "r");
	while ($file && !feof($file))
	{
		echo "Entrez votre commande: ";
		$command = fgets($file);
		if (!empty($command))
			eval($command);
    }
	fclose($file);
	echo ("\n");
?>
