<?php
abstract Class Fighter
{
	private $type;
	public function __Construct($arg)
	{
		$this->type = $arg;
	}
	public function type_Fighter()
	{
		return ($this->type);
	}
	abstract public function fight($target);
}
?>
