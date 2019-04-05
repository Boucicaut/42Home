<?php
Trait is_conflictwith
{
	final public function is_conflictwith($args)
	{
			/* collision between both instance */
		foreach($args as $arg)
		{
			if (($this->taille->x >= $arg->pos->x && ($this->taille->x) <= ($arg->pos->x + $arg->pos->x_l)) && ($this->taille->y >= $arg->pos->y && ($this->taille->y) <= ($arg->pos->y + $arg->pos->y_l)))
				return (true);
			if (($this->taille->x + $this->taille->x_l >= $arg->pos->x && ($this->taille->x + $this->taille->x_l) <= ($arg->pos->x + $arg->pos->x_l)) && ($this->taille->y >= $arg->pos->y && ($this->taille->y) <= ($arg->pos->y + $arg->pos->y_l)))
				return (true);
			if (($this->taille->x + $this->taille->x_l >= $arg->pos->x && ($this->taille->x + $this->taille->x_l) <= ($arg->pos->x + $arg->pos->x_l)) && ($this->taille->y + $this->taille->y_l >= $arg->pos->y && ($this->taille->y + $this->taille->y_l) <= ($arg->pos->y + $arg->pos->y_l)))
				return (true);
			if (($this->taille->x >= $arg->pos->x && ($this->taille->x) <= ($arg->pos->x)) && ($this->taille->y + $this->taille->y_l >= $arg->pos->y && ($this->taille->y + $this->taille->y_l) <= ($arg->pos->y + $arg->pos->y_l)))
				return (true);
		}
		return (false);
	}
	final public function is_conflictwithborder()
	{
			/* collision with map-borders */
			if (($this->taille->x + $this->taille->x_l >= 150 || $this->taille->x + $this->taille->x_l < 0 || $this->taille->x < 0) || ($this->taille->y + $this->taille->y_l >= 100 || $this->taille->y < 0 || $this->taille->y + $this->taille->y_l < 0))
				return (true);
			return (false);
	}
}
?>
