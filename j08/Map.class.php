<?php
Class	Map
{
	public	$long = 150;
	public	$larg = 100;
	public	$mapp = array();

	public function init_map()
	{
		for ($i = 0; $i < 150; $i++)
		{
			for ($j = 0; $j < 100; $j++)
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
			for ($i = 0; $i < 150; $i++)
			{
				for ($j = 0; $j < 100; $j++)
				{
					if ($i >= $ob->x && $i <= ($ob->x + $ob->x_l) && $j >= $ob->y && $j <= ($ob->y + $ob->y_l))
						$this->map[$i][$j] = 'x';
				}
			}
		}
	}
	public function display()
	{
		for ($i = 0; $i < 150; $i++)
		{
			for ($j = 0; $j < 100; $j++)
			{
				echo $this->map[$i][$j];
			}
			echo "\n";
		}
	}
}
?>
