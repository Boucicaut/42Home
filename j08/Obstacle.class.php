<?php
include_once 'Iobstacle.class.php';
include_once 'TgetAttacked.class.php';
Class obstacle implements obstacle_interface
{
	use getAttacked;

	public $pos;
	public $pdv;

	public function __Construct($pos, $pdv)
	{
		$this->pos = $pos;
		$this->pdv = $pdv;
	}
	final public function getpdv()
	{
		return $this->pdv;
	}
}
?>
