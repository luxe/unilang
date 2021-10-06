<!DOCTYPE html>

<html>
<head>
	<?php include 'headnavfoot/head_data.php'; ?>
<title>   Jstd Library </title>

</head>

<body>
<div id="wrapper">
	<div id="header">
	
        	<!--header -->
		<?php include 'headnavfoot/header.php'; ?>
		
		<!-- Navigation Bar -->
		<?php include 'headnavfoot/navigation.php'; ?>
		<?php echo Navigation::GenerateMenu($menu); ?>
	</div>
	
	
		<div class="contactBox">
		
			<div id="joshImg">
				<img src="images/sushi.jpg"  alt="Joshua"/>
			</div>
			
			<div id="contactTblJosh">
			<h4>Joshua Genis</h4>
			<p> Email: <a href="mailto:jtgenis@gmail.com">jtgenis@gmail.com</a> <br />
			    Twitter: <a href="http://www.twitter.com/shuagenis" title="twitter.com/ShuaGenis">@ShuaGenis</a>
			</p>
			</div>
			
			<div id="joshDesc">
				<ul>
					<li>
					<h5>Jstd founder</h5>
					</li>
					
					<li>
					<h5>Jstd website designer</h5>
					</li>
				</ul>
			</div>
		</div>
		<br />
		<div class="contactBox">
		
			<div id="contactTblHickey">
				<h4>Trevor Hickey</h4>
				<p> Email: <a href="mailto:TrevorJamesHickey@gmail.com">TrevorJamesHickey@gmail.com</a> <br />
					Twitter: <a href="http://www.twitter.com/trev0rr" title="twitter.com/trev0rr"> @trev0rr</a>
			</div>
			
			<div id="hickeyImg">
			
					
			
					<img src="images/mapel.png"  alt="mapel syrup connoisseurs"/>

			</div>
			
			<div id="trevorDesc">
			<h5>Jstd contributor</h5>
			</div>
			
		</div>
		
		<!-- FOOTER -->
		<?php include "headnavfoot/footer.php"; ?>

</div>
</body></html>