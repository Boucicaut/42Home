<?php
	include_once 'Iship.class.php';
	include_once 'Pos.class.php';
Class Ship implements ships_interface
{
	use getAttacked;
	use is_conflictwith;
	public	$nom;
	public	$taille;
	public	$display;
	public	$pdv;
	public	$power;
	public	$speed;
	public	$manoeuvre;
	public	$shield;
	public	$weapons;

	public function __Construct($args)
	{
		$this->nom = $args['nom'];
		$this->taille = $args['taille']; // pos
		$this->display = $args['display']; // 'A', 'B'
		$this->pdv = $args['pdv'];	// pdv 
		$this->speed = $args['speed'];
		$this->manoeuvre = $args['manoeuvre'];
		$this->weapons = $args['weapons'];
		$this->shield = $args['shield'];
		$this->power = $args['power'];
	}
	public function movement($args)
	{
		$dir = $args['dir'];
		$vit = intval($args['vit']);
		if ($vit > 0 && $vit > $this->speed)
			$vit = $this->speed;
		if ($vit < 0 && -$vit > $this->speed)
			$vit = -$this->speed;
		if ($dir == 'y')
			$this->taille->y += $vit;
		else if ($dir == 'x')
			$this->taille->x += $vit;
		if ($this->is_conflictwithborder())
			$this->pdv = 0;
	}
	public function shoot($arg)
	{
		if ($arg == 'x')
			$this->weapon = new Pos(array('x' => ($this->taille->x + 3), 'y' => $this->taille->y, 'x_l' => 10, 'y_l' => 10));
		else if ($arg == 'x2')
			$this->weapon = new Pos(array('x' => $this->taille->x - 10, 'y' => $this->taille->y, 'x_l' => 10, 'y_l' => 10));
		else if ($arg == 'y2') // bas
			$this->weapon = new Pos(array('y' => $this->taille->y + 3, 'x' => $this->taille->x, 'x_l' => 10, 'y_l' => 10));
		else if ($arg == 'y') // haut
			$this->weapon = new Pos(array('y' => ($this->taille->y - 10), 'x' => $this->taille->x, 'x_l' => 10, 'y_l' => 10));
		return ($this->weapon);
	}
}
?>
