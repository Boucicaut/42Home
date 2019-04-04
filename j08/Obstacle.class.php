<?php
include_once 'Littleobstacle.class.php';
include_once 'Bigobstacle.class.php';
abstract Class obstacle
{
	public $x;
	public $y;
	public $x_l;
	public $y_l;
	public $pdv;

	public function __Construct($args)
	{
		$this->x = $args['x'];
		$this->y = $args['y'];
		$this->x_l = $args['x_l'];
		$this->y_l = $args['y_l'];
		$this->pdv = $args['pdv'];
	}
	abstract public function getAttacked($arg);
	final public function getPDV()
	{
		return $this->pdv;
	}
}
?>
