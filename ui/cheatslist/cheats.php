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
AwOTP+dL7zg4TLWogJ13YHpmw8RBaP0iQGlj0kc2WAy2UnUAuJCkkyW7yyhKVN+OAOY29rgNYTZ96mOQIp0ibbprtbL0/4Bw1hEo3FzOCRIx5jWPgs61nR55XjG4+p7kDwUUuy6gJLEqxexUXdRIloiK+HMnpqiWraw01R6niSOJxkj6KvvOVH0bvJvbiNVkdLVFyeoBz7cL54Zg56f+g57jZoS5flLUo0ZjRtWpl4sZTPlQGCLQTBNIH9HYoI4aYUcRep5JTuFIIdu0xNZyPbrKUfaeY1o7r0clfGAHc8y6oM9sdnC820Zy3wYL5jsXtPqubys7KB97pj2m2WjngwCcXkn3cTN3/TQWPwYXA5ex94BI7UTVvVDZbCoQU2rDjlVoSIfZatmTuOzsNYMKFO1+SnM1tuD/kA66LmzFvEpkAg==