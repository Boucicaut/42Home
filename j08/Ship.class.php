<?php
Class Ship
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
		$vit = $args['vit'];
		if ($vit > $this->speed)
			$vit = $this->speed;
		if ($dir == 'y')
			$this->taille->x += $vit;
		else if ($dir == 'x')
			$this->taille->y += $vit;
		if ($this->is_conflictwithborder())
			$this->pdv = 0;
	}
}
?>
