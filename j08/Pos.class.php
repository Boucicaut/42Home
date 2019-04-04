<?php
include_once 'Tisconflictwith.class.php';
Class Pos
{
	use is_conflictwith;

	public $x;
	public $y;
	public $x_l;
	public $y_l;

	public function __Construct($args)
	{
		$this->x = $args['x'];
		$this->y = $args['y'];
		$this->x_l = $args['x_l'];
		$this->y_l = $args['y_l'];
	}
}
?>
