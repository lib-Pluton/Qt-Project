<?php 
function getkey()
{
  $hour =  date("h") + 3; 
  $minute = date("i"); 
  $son = $hour + $minute * 7 * 9 + 20000000;
  return $son;
}
$security=$_GET['security'];
  if($security != getkey()){
	 header("Location: https://cheatofkings.org/");
  }
?> 
test