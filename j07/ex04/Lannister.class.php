<?php
class Lannister
{
	public function sleepWith($arg)
	{
		if ($arg INSTANCEOF Lannister)
			echo "Not even if I'm drunk !\n";
		else
			echo "Let's do this.\n";
	}
}
?>
