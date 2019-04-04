<?php
Class	Map
{
	public	$long = 150;
	public	$larg = 100;
	public	$mapp = array();

	public function init_map()
	{
		for ($i = 0; $i < 100; $i++)
		{
			for ($j = 0; $j < 150; $j++)
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
			for ($i = 0; $i < 100; $i++)
			{
				for ($j = 0; $j < 150; $j++)
				{
					if ($i >= $ob->pos->x && $i <= ($ob->pos->x + $ob->pos->x_l) && $j >= $ob->pos->y && $j <= ($ob->pos->y + $ob->pos->y_l))
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
			for ($i = 0; $i < 100; $i++)
			{
				for ($j = 0; $j < 150; $j++)
				{
					if ($i >= $ship->taille->x && $i <= ($ship->taille->x + $ship->taille->x_l) && $j >= $ship->taille->y && $j <= ($ship->taille->y + $ship->taille->y_l))
					{
						$this->map[$i][$j] = $ship->display;
					}
				}
			}
		}
	}
	public function init_shoot($args) // pos de tous les shots, pos de tous les ships, pos de tous les obs
	{
		$obs = $args['obs'];
		$shots = $args['shots'];
		$ships = $args['ships'];
		foreach ($shots as $shot)
		{
			foreach ($obs as &$ob) // & ????
			{
				if ($shot->is_conflictwith($ob))
					$ob->getAttacked(1);
			}
			foreach ($ships as &$ship) // & ????
			{
				if ($shot->is_conflictwith($ship))
					$ship->getAttacked(1);
			}
		}
	}
	public function display()
	{
		echo "<span style=\"letter-spacing: 1px; color: blue;\">";
		for ($i = 0; $i < 100; $i++)
		{
			for ($j = 0; $j < 150; $j++)
			{
				echo ($this->map[$i][$j] . " ");
			}
			echo "<br />";
		}
		echo "</span>";
	}
}
?>
