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
AwP5jcNvyw78iHEkCv/Jx93BZEuBp1+Lth7bCpTwaafW3GovLjYSK9JRln8G+CvEShRkWCJxYK4tFrwv5YVetXCL04CUySxAKV5oiE0yzOUs2HbxGOo3tRg/qNsSm11t10foiM9A2ztozahcI/EelBRtWW+oTxcuwLBgB3rK9KWKLrqG/VMj7KHMiJdondEfC69wcforTFkmAIJWm5cgjrbgvpa0q1M9xdzcy2e8s52X24ci0PWu9NAFFQ4kLsFB6+fts5fawpfM6TiNXeqVZXilUXdbTR/Fm1UpGPGQ5AusXPAqtFF4hbf/57MfZelUjpv+aTnFXcgPrUaGatRzU/klA0emu28pX/QS4l1SQmU8ZE06orSRz6bcGitTc4oTdb7Tb5l7myxXZbCsozH2svJrg0K9DU37hA9O0aWTz3nBn/nL1OPvJz/Ij5k3ilPZTn9422uLOl5hreqF9maRoMYYXM3Qrmgd3dXM890JrKkD0DGsLcncYO/5JimQtTvXXZ/7iZdjqPjWlQd5wGV1NBAGU27Z22+BkxBAmvsiv4nSD1nweKY20LomfYeOYn0GSmiNRG8VXCUaWPwdB15GVoRQmfVx92NxDM0muhKAkXhjFAzND5jR6S6WBkErSTOPOrWVIO5uhYM1M/LzUotS9Tak/wjsrZ2hyRlFoaBF9gACf+81Uf2P+xLwyRn4K2gSObfhA8xt32CdlqOdJcb8J0qcmx60b8YhY0x8IdGjtE98vadNERZbdDgiJyoz3lWWqswf3JFY02ckSzG1CzGj4Y5dHyaUX8DF4RVX6NBXv3TtbPdl1YSB9F8Z0i05mwt6Fyi+gw6NfO7us9yFbfo5kBlQqvFciKWEwKV01r46vqPCW96Z7MJklV50C+uBzMsm8gdRXztjFUhRpXK5aoL510O6Xx1b8PuUCKmGFdYCjzA0/PANKlgYNGO64HJpFf3skHo5TFTi38pHBEmLZW9BsuCxY7llwDq5BzZeePbGVvQQEOnPMA+lBnqAQfYUBkRPUSamyEZI/7u/EKrE5mMc5OClTHDuINSZdQ==