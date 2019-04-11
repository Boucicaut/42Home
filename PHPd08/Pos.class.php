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
	public static function doc()
	{
		$file = file_get_contents("Pos.doc.txt");
		return ($file);
	}
	public function __ToString()
	{
		echo "X : $this->x" . "\n";
		echo "X_L : $this->x_l" . "\n";
		echo "Y : $this->y" . "\n";
		echo "Y_L : $this->y_l" . "\n";
	}
}
?>
