<?php
require_once 'Map.class.php';
require_once 'Obstacle.class.php';

$map = new Map();
$map->init_map();

$big = array('x' => 10, 'y' => 20, 'x_l' => 20, 'y_l' => 10, 'pdv' => 50);
$little = array('x' => 40, 'y' => 90, 'x_l' => 5, 'y_l' => 10, 'pdv' => 20);
$little2 = array('x' => 100, 'y' => 30, 'x_l' => 10, 'y_l' => 10, 'pdv' => 20);
$obs = array(new Littleobstacle($little), new Bigobstacle($big), new Littleobstacle($little2));
$map->init_obs($obs);

$map->display();
?>
