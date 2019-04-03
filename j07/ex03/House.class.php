<?php
abstract Class House
{
	abstract function getHouseName();
	abstract function getHouseMotto();
	abstract function getHouseSeat();
	public function introduce()
	{
		echo "House " . $this->getHouseName() . " of " . $this->getHouseSeat() . " : \"" . $this->getHouseMotto() . "\"\n";
	}
}
?>
