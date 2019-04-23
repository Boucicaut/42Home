<?php
include_once 'Map.class.php';
include_once 'Obstacle.class.php';
include_once 'Pos.class.php';
include_once 'Ship.class.php';

session_start();

if ($_SESSION['save'] != 1)
{
$map = new Map(150, 100);
$map->init_map();

	/* INIT DES SHIPS */
$shipApos = new Pos(array('x' => 130, 'y' => 5, 'x_l' => 4, 'y_l' => 4));
$shipA = new Ship(array('taille' => $shipApos, 'nom' => 'A', 'display' => 'A', 'pdv' => 10, 'shield' => 5, 'speed' => 25));
$shipBpos = new Pos(array('x' => 10, 'y' => 40, 'x_l' => 4, 'y_l' => 4));
$shipB = new Ship(array('taille' => $shipBpos, 'nom' => 'B', 'display' => 'B', 'pdv' => '10', 'shield' => 5, 'speed' => 25));
$map->init_ships(array($shipA, $shipB));

	/* INIT DES OBSTACLES */
$bigpos = new Pos(array('x' => 10, 'y' => 20, 'x_l' => 20, 'y_l' => 10));
$big = new Obstacle($bigpos, 30);
$littlepos = new Pos(array('x' => 100, 'y' => 45, 'x_l' => 10, 'y_l' => 10));
$little = new Obstacle($littlepos, 10);

$little2pos = new Pos(array('x' => 130, 'y' => 15, 'x_l' => 10, 'y_l' => 10));
$little2 = new Obstacle($little2pos, 10);
$map->init_obs(array(($little), ($big), ($little2)));

	/* STORE DATA IN COOKIE SESSION */
	$_SESSION['map'] = $map;
	$_SESSION['ships'] = array($shipA, $shipB);
	$_SESSION['obs'] = array($little, $little2, $big);
	$_SESSION['save'] = 1;

	/* DISPLAY DE LA MAP */
	$map->display();
}
else if ($_GET['submit'] == "OK")
{
	/* RECUPERE L'ETAT DU JEU */
	$map = $_SESSION['map'];
	$shipA = $_SESSION['ships'][0];
	$shipB = $_SESSION['ships'][1];
	$little = $_SESSION['obs'][0];
	$little2 = $_SESSION['obs'][1];
	$big = $_SESSION['obs'][2];

	/* DEROULEMENT D'UN TOUR */
	if ($_GET['shipname'] == "shipa" && $_GET['vit'] != 0)
		$shipA->movement(array('dir' => $_GET['direction'], 'vit' => $_GET['vit']));
	else if ($_GET['shipname'] == "shipb" && $_GET['vit'] != 0)
		$shipB->movement(array('dir' => $_GET['direction'], 'vit' => $_GET['vit']));
		/* CHECK CONFLICT */
	if (($shipA->is_conflictwith(array($little, $little2, $big))) || $shipA->is_conflictwithborder())
		$shipA->pdv = 0;
	if (($shipB->is_conflictwith(array($little, $little2, $big))) || $shipB->is_conflictwithborder())
		$shipB->pdv = 0;

	if ($shipA->is_conflictwith(array(new Obstacle($shipB->taille, 0))))
	{
		$shipA->pdv = 0;
		$shipB->pdv = 0;
	}

/* ATTAQUE ICI */
	if ("shipa" == $_GET['player'] && $shipA->pdv)
	{
		$shot = $shipA->shoot($_GET['angle']);
		if ($shipB->is_conflictwith(array(new Obstacle($shot, 0))))
		{
			echo "OK";
			if ($_GET['angle'] == 'x')
				$shipB->movement(array('dir' => x, 'vit' => 20));
			else if ($_GET['angle'] == 'x2')
				$shipB->movement(array('dir' => x, 'vit' => -20));
			else if ($_GET['angle'] == 'y2')
				$shipB->movement(array('dir' => y, 'vit' => 20));
			else if ($_GET['angle'] == 'y')
				$shipB->movement(array('dir' => y, 'vit' => -20));
		}
	}
	else if ("shipb" == $_GET['player'] && $shipB->pdv)
	{
		$shot = $shipB->shoot($_GET['angle']);
		if ($shipA->is_conflictwith(array(new Obstacle($shot, 0))))
		{
		$shot = $shipB->shoot($_GET['angle']);
			if ($_GET['angle'] == 'x')
				$shipA->movement(array('dir' => x, 'vit' => 20));
			else if ($_GET['angle'] == 'x2')
				$shipA->movement(array('dir' => x, 'vit' => -20));
			else if ($_GET['angle'] == 'y2')
				$shipA->movement(array('dir' => y, 'vit' => 20));
			else if ($_GET['angle'] == 'y')
				$shipA->movement(array('dir' => y, 'vit' => -20));
		}
	}
		/* CHECK CONFLICT */
	if (($shipA->is_conflictwith(array($little, $little2, $big))) || $shipA->is_conflictwithborder())
		$shipA->pdv = 0;
	if (($shipB->is_conflictwith(array($little, $little2, $big))) || $shipB->is_conflictwithborder())
		$shipB->pdv = 0;

	/* STORE DATA IN COOKIE SESSION */
$_SESSION['map'] = $map;
$_SESSION['ships'] = array($shipA, $shipB);
$_SESSION['obs'] = array($little, $little2, $big);
$map->init_map();
$map->init_obs(array($little, $big, $little2));
$map->init_ships(array($shipA, $shipB));
$map->display();
/* FIN DU GAME SI PDV == 0 */
if ($shipA->pdv == '0' || $shipB->pdv == '0')
{
	if ($shipA->pdv == 0 && $shipB->pdv == 0)
	{
		echo ("<a href='jeu.php'><div style='font-style:9em; margin-top: -200px; margin-left: 600px; width: 300px; height: 100px; background-color: red; color: yellow; text-decoration: bold; border: 3px black solid'><p>C\'est une egalite, super.</p></div></a>");
	}
	if ($shipA->pdv == 0)
	{
		echo ("<a href='jeu.php'><div style='font-style=9em; margin-top: -200px; margin-left: 600px; width: 300px; height: 100px; background-color: red; color: yellow; text-decoration: bold; border: 3px black solid'><p>Le ShipB a gagne, super.</p></div></a>");
	}
	else
		echo ("<a href='jeu.php'><div style='font-style: 9em; margin-top: -200px; margin-left: 600px; width: 300px; height: 100px; background-color: red; color: yellow; text-decoration: bold; border: 3px black solid'><p>Le ShipA a gagne, genial.</p></div></a>");
	$_SESSION['save'] = 0;
}
}
else
	$_SESSION['save'] = 0;
?>
<html>
	<head>
<style>
	h1,h2,p {
		text-align: center;
		margin-top: 20px;
	}
	form {
		margin: auto;
		width: 50%;
		height: 100px;
		border: 2px grey solid;
	}
	button {
		width: 100%;
		height: 60%;
	}
	.but {
		height: 100%;
	}
	option, select {
		margin-left: 20%;
		text-align: center;
	}
	.nd {
		height: 200px;
	}
	.butt {
		margin-top: 1%;
		height: 23%;
	}
	hr {
		margin-top: 13px;
		border: 1px black solid;
	}
</style>
	</head>
	<body>
<hr>
		<h1>Tableau de controle du vaisseau</h1>
		<form method="GET" action='jeu.php'>
			<button class="but" type="submit" name="reset" value="OK">New game</button>
		</form>
		<h2>Mouvement et Attaque</h2>
			<form class="nd" action='jeu.php' method="GET">
	<p>Deplacement</p>
				<select name="shipname">
					<option value="shipa">ShipA</option>
					<option value="shipb">ShipB</option>
				</select>
				<select name="direction">
					<option value="x">Axe X</option>
					<option value="y">Axe Y</option>
				</select>
				<input type="number" placeholder="Distance : 10" name="vit">
	<p>Combat</p>
				<select name="player">
					<option value="shipa">ShipA</option>
					<option value="shipb">ShipB</option>
				</select>
				<select name="angle">
					<option value="x">Droite</option>
					<option value="x2">Gauche</option>
					<option value="y">Haut</option>
					<option value="y2">Bas</option>
				</select>
				<button class="butt"  type="submit" name="submit" value="OK">Action</button>
			</form>

	</body>
</html>
