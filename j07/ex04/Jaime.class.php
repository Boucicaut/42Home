<?php
class Jaime extends Lannister
{
	public function sleepWith($arg)
	{
		if ($arg INSTANCEOF Cersei)
			echo "With pleasure, but only in a tower in Winterfell, then.\n";
		else
			parent::sleepWith($arg);
	}
}
?>
