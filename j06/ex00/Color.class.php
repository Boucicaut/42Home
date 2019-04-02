<?php
class	Color
{
	public $red;
	public $green;
	public $blue;
	public static $verbose = False;

	public function __Construct(array $args)
	{
		if (isset($args['red']) && isset($args['blue']) && isset($args['green']))
		{
			$this->red = intval($args['red']);
			$this->blue = intval($args['blue']);
			$this->green = intval($args['green']);
		}
		else if (isset($args['rgb']))
		{
			/*$this->red = intval(($args['rgb'] >> 16));
			$this->green = intval(($args['rgb'] << 8) >> 16);
			$this->blue = intval(($args['rgb'] << 16) >> 16);*/
			$this->red = (intval($args['rgb']) & 0xff0000) >> 16;
			$this->green = (intval($args['rgb']) & 0x00ff00) >> 8;
			$this->blue = (intval($args['rgb']) & 0x0000ff) >> 0;
		}
		if (self::$verbose == True)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
	}
	public function __Destruct()
	{
		if (self::$verbose == True)
			printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue);
	}
	public function __ToString()
	{
		return (sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue));
	}
	public function add($Color)
	{
		$array = array('red' => ($this->red + $Color->red), 'green' => ($this->green + $Color->green), 'blue' => ($this->blue + $Color->blue));
		return (new Color($array));
	}
	public function sub($Color)
	{
		$array = (array('red' => ($this->red - $Color->red), 'green' => ($this->green - $Color->green), 'blue' => ($this->blue - $Color->blue)));
		return (new Color($array));
	}
	public function mult($prod)
	{
		$array = (array('red' => ($this->red * $prod), 'green' => ($this->green * $prod), 'blue' =>($this->blue * $prod)));
		return (new Color($array));
	}
	public static function doc()
	{
		$doc = "Color.doc.txt";
		$doc = file_get_contents($doc);
		echo $doc;
	}
}
?>
