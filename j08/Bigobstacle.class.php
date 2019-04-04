<?php
Class	Bigobstacle extends obstacle
{
	public function getAttacked($arg)
	{
		$this->pdv -= (intval($arg) / 2);
		return ($this->pdv);
	}
}
?>
