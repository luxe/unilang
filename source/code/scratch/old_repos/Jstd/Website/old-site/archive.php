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
	
	<div id="archiveHead">
	<h2>Archive</h2>
	</div>
	
	<div id="archiveContent">
	<?php
		require_once('fry/banana.php');
		$db_server= mysqli_connect($db_hostname,$db_username,$db_password, $db_database);
		if(!db_server)
			die ("unable to connect to MySQL" .mysqli_error());


		$query="SELECT * FROM newsContent ORDER BY newsId DESC";
		$results = mysqli_query($db_server,$query);
		while($row=mysqli_fetch_array($results))
		{	
			echo '<div class="newsBox">
			';
			print("<h4>$row[date]</h4>  <p>$row[content]</p>");
			echo '<div class ="newsAuth">';
			print ("<p>-$row[author]</p>");
			echo '</div>';
			echo '</div>
			';
		}
		mysqli_close($db_server);
		?>
	</div>
	
		
		<!-- FOOTER -->
		<?php include "headnavfoot/footer.php"; ?>

</div>
</body></html>
