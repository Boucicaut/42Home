<?php
Class	Map
{
	protected static	$_long;//= 150;
	protected static	$_larg;// = 100;
	public				$map = array();

	public function __Construct($long, $larg)
	{
		if (!(isset($long) && isset($larg)))
			exit();
		self::$_long = $long;
		self::$_larg = $larg;
	}
	public function init_map()
	{
		for ($i = 0; $i < 55; $i++)
		{
			for ($j = 0; $j < 180; $j++)
			{
				$this->map[$i][$j] = '.';
			}
		}
		return ($this->map);
	}
	public function	init_obs($obs)
	{
		foreach ($obs as $ob)
		{
			if ($ob->pdv == 0)
				continue ;
			for ($i = 0; $i < 55; $i++)
			{
				for ($j = 0; $j < 180; $j++)
				{
					if ($j >= $ob->pos->x && $j <= ($ob->pos->x + $ob->pos->x_l) && $i >= $ob->pos->y && $i <= ($ob->pos->y + $ob->pos->y_l))
					{
						$this->map[$i][$j] = '/';
					}
				}
			}
		}
	}
	public function init_ships($ships)
	{
		foreach ($ships as $ship)
		{
			if ($ship->pdv == 0)
				continue ;
			for ($i = 0; $i < 55; $i++)
			{
				for ($j = 0; $j < 180; $j++)
				{
					if ($j >= $ship->taille->x && $j <= ($ship->taille->x + $ship->taille->x_l) && $i >= $ship->taille->y && $i <= ($ship->taille->y + $ship->taille->y_l))
					{
						$this->map[$i][$j] = $ship->display;
					}
				}
			}
		}
	}
	public function display()
	{
		echo "<span style=\"letter-spacing: 1px; color: blue;\">";
		for ($i = 0; $i < 55; $i++)
		{
			for ($j = 0; $j < 180; $j++)
			{
				echo ($this->map[$i][$j] . " ");
			}
			echo "<br />";
		}
		echo "</span>";
	}
	public function __ToString()
	{
		return (sprintf(self::$_larg . ", " . self::$_long));
	}
	public static function doc()
	{
		$file = file_get_contents("Map.doc.txt");
		return ($file);
	}
}
?>
