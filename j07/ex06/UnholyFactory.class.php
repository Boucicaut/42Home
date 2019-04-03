<?php
Class UnholyFactory
{
	private $fighters_abs = array();
	public function __Construct()
	{
	}
	public function absorb($arg)
	{
		if ($arg INSTANCEOF Fighter)
		{
			foreach ($this->fighters_abs as $fighter)
			{
				if (get_class($fighter) == get_class($arg))
				{
					echo ("(Factory already absorbed a fighter of type " . $arg->type_Fighter() . ")\n");
					return;
				}
			}
			$this->fighters_abs[] = $arg;
			echo ("(Factory absorbed a fighter of type " . $arg->type_Fighter() . ")\n");
		}
		else
			echo ("(Factory can't absorb this, it's not a fighter)\n");
	}

	public function fabricate($arg)
	{
		foreach ($this->fighters_abs as $fi_ab)
		{
			if ($fi_ab->type_Fighter() == $arg)
			{
				echo ("(Factory fabricates a fighter of type " . $fi_ab->type_Fighter() . ")\n");
				return (clone $fi_ab);
			}
		}
		echo ("(Factory hasn't absorbed any fighter of type " . $arg . ")\n");
	}

	public function fight($arg)
	{
		if ($arg INSTANCEOF Fighter)
			$arg->fight();
	}
}
?>
