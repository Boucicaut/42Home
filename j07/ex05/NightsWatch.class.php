<?php
class NightsWatch
{
	private $members = array();
	public function recruit($arg)
	{
		if ($arg INSTANCEOF IFighter)
			$this->members[] = $arg;
	}
	public function fight()
	{
		foreach ($this->members as $member)
		{
			print($member->fight());
		}
	}
}
?>
