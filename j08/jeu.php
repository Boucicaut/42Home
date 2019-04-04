<?php
include_once 'Map.class.php';
include_once 'Obstacle.class.php';
include_once 'Pos.class.php';
include_once 'Ship.class.php';

$map = new Map();
$map->init_map();

	/* INIT DES SHIPS */
$shipApos = new Pos(array('x' => 3, 'y' => 95, 'x_l' => 3, 'y_l' => 3));
if (!($shipA INSTANCEOF Ship) && $_GET['OK'] != "OK")
$shipA = new Ship(array('taille' => $shipApos, 'nom' => 'A', 'display' => 'A', 'pdv' => 10, 'shield' => 5, 'speed' => 25));
$shipBpos = new Pos(array('x' => 85, 'y' => 3, 'x_l' => 3, 'y_l' => 3));
if (!($shipB INSTANCEOF Ship) && $_GET['OK'] != "OK")
$shipB = new Ship(array('taille' => $shipBpos, 'nom' => 'B', 'display' => 'B', 'pdv' => 10, 'shield' => 5, 'speed' => 25));
$map->init_ships(array($shipA, $shipB));

	/* INIT DES OBSTACLES */
$bigpos = new Pos(array('x' => 10, 'y' => 20, 'x_l' => 20, 'y_l' => 10));
$big = new Obstacle($bigpos, 30);
$littlepos = new Pos(array('x' => 40, 'y' => 90, 'x_l' => 5, 'y_l' => 10));
$little = new Obstacle($littlepos, 10);

$little2pos = new Pos(array('x' => 90, 'y' => 70, 'x_l' => 10, 'y_l' => 10));
$little2 = new Obstacle($little2pos, 10);
$map->init_obs(array(($little), ($big), ($little2)));

	/* DISPLAY DE LA MAP */
if ($_GET['submit'] != "OK")
	$map->display();

if ($_GET['submit'] == "OK")
{
	/* DEROULEMENT D'UN TOUR */
	if ($_GET['shipname'] == "shipa")
		$shipA->movement(array('dir' => $_GET['direction'], 'vit' => $_GET['distance']));
	else if ($_GET['shipname'] == "shipb")
		$shipB->movement(array('dir' => $_GET['direction'], 'vit' => $_GET['distance']));

/*	if ($_GET['direction'] == 'X' || $_GET['direction'] == 'x')
		$new_pos = new Pos(array('x' => ($_GET['distance'] + $curr_ship->taille->x), 'y' => $curr_ship->taille->y, 'x_l' => $curr_ship->taille->x_l, 'y_l' => $curr_ship->taille->y_l));
	$curr_ship = new Ship(array*/

$map->init_map();
$map->init_obs(array(($little), ($big), ($little2)));
$map->init_ships(array($shipA, $shipB));
$map->display();
}

?>
<html>
	<head>
<style>
	form {
		float: ;
		border: 2px grey solid;
	}
</style>
	</head>
	<body>
		<h1>Tableau de controle du vaisseau</h1>
		<h2>Mouvement</h2>
			<form action='jeu.php' method="GET">
				<input type="text" placeholder="Shipname" name="shipname">
				<input type="text" placeholder="Direction : X/Y" name="direction">
				<input type="number" placeholder="Distance : 10" name="distance">
				<button type="submit" name="submit" value="OK">Se deplacer</button>
			</form>
		<h2>Attaque</h2>
			<form action='jeu.php' method="GET">
				<input type="text" placeholder="Shipname" name="shipname">
				<input type="text" placeholder="Direction" name="direction">
				<button type="submit" name="submit">Se deplacer</button>
			</form>

	</body>
</html>
