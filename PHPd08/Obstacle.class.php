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
	public function __ToString()
	{
		echo "Instance : pdv = $this->pdv";
		print_r($pos);
	}
	public static function doc()
	{
		$file = file_get_contents("Obstacle.doc.txt");
		return ($file);
	}
}
?>
