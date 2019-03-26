#!/usr/bin/php
<?php
	if ($argc != 2)
		exit();

	$file = fopen('php://stdin', 'r');
	while ($file && !feof($file))
		$tab[] = fgets($file);
	unset($tab[0]);

if ($argv[1] == "moyenne")
{
	$nb = 0;
	$avg = 0;
	foreach ($tab as $i)
	{
		$note = explode (";", $i);
		if ($note[1] != "" && $note[2] != "moulinette")
		{
			$avg += $note[1];
			$nb++;
		}
	}
	echo $avg / $nb."\n";
}
else if ($argv[1] == "moyenne_user" || $argv[1] == "ecart_moulinette")
{
	asort($tab);
	foreach ($tab as $key => $i)
	{
		$tmp = explode (";", $i);
		$array[$tmp[0]][$key] = $i;
	}
	foreach ($array as $user)
	{
		$nb_note = 0;
		$nb_user = 0;
		$moyenne = 0;
		$note_mou = 0;
		foreach ($user as $line)
		{
			$note = explode (";", $line);
			if (strlen($note[1]) && $note[2] != "moulinette")
			{
				$nb_user += $note[1];
				$nb_note++;
			}
			if ($note[2] == "moulinette")
				$note_mou = $note[1];
		}
		if ($nb_note != 0)
		{
			$moyenne = $nb_user / $nb_note;
			if ($argv[1] == "moyenne_user")
				echo $note[0].":".$moyenne."\n";
			else if ($argv[1] == "ecart_moulinette")
				echo $note[0].":".($moyenne - $note_mou)."\n";
		}	
	}
}
?>
