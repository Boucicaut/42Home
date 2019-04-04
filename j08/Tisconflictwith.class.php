<?php
Trait is_conflictwith
{
	final public function is_conflictwith($arg)
	{
			/* collision between both instance */
		if (($this->x >= $arg->x && ($this->x + $this->x_l) <= ($arg->x + $arg->x_l)) && ($this->y >= $arg->y && ($this->y + $this->y_l) <= ($arg->y + $arg->y_l)))
			return (true);
		return (false);
	}
	final public function is_conflictwithborder()
	{
			/* collision with map-borders */
			if (($this->x + $this->x_l >= 150 || $this->x + $this->x_l < 0 || $this->x < 0) || ($this->y + $this->y_l >= 100 || $this->y < 0 || $this->y + $this->y_l < 0))
				return (true);
			return (false);
	}
}
?>
