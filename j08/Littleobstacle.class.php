<?php
Class	Littleobstacle extends obstacle
{
	public function getAttacked($arg)
	{
		$this->pdv -= intval($arg);
		return ($this->pdv);
	}
}
?>
