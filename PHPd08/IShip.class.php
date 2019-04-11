<?php
	interface ships_interface
	{
			/* Genere une nvlle pos du ship */
		public function movement($arg); //$arg = new Pos

			/* Attaque un autre truc (ship ou obstacle) */
		public function	shoot($pos);

			/* Se fait attaquer */
		public function getAttacked($args);

			/* Check conflict : with map-border / autre objet */
		public function is_conflictwith($arg);
		public function is_conflictwithborder();
	}
?>
