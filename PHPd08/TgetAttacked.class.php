<?php
trait getAttacked
{
	public function getAttacked($arg)
	{
		if (isset($this->shield))
		{
			if ($this->shield > $arg)
			{
				$this->shield -= $arg;
				$arg = 0;
			}
			else
			{
				$arg -= $this->shield;
				$this->shield = 0;
			}
		}
		$this->pdv -= $arg;
		return ($this->pdv);
	}
}
?>
