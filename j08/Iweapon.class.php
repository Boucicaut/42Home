<?php
	interface weapon_interface
	{
			/* Taille du tir */
		public abstract $pos;

			/* Attaque un ship */
		public function	shoot($pos);

			/* Se fait attaquer */
		public function getAttacked($args);

			/* Check conflict : with map-border / autre objet */
		public function is_conflictwith($arg);
		public function is_conflictwithborder();
	}
?>
