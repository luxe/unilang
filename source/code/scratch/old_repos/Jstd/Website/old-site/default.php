<!DOCTYPE html>

<html>
<head>
	<?php include 'headnavfoot/head_data.php'; ?>
	
<title>   Jstd Library </title>

</head>

<body>
<div id="wrapper">	
	<div id ="header">
		<!--header -->
		<?php include 'headnavfoot/header.php'; ?>

		<!-- Navigation Bar -->
		<?php include 'headnavfoot/navigation.php'; ?>
		<?php echo Navigation::GenerateMenu($menu); ?>
		<!-- <?php //echo Navigation::GenerateSubMenu($docSubMenu); ?> -->
	</div>
		<div id="objective">
		<h1>The Jstd Library</h1>
		<p> This is the Jstd Library! It is an open source project with the goal to create a massive c++ library of functions.
		This library will have functions for everything. This library is unique in its use of function synonyms. The overall
		goal of the Jstd is to prevent yak shaving.
		</p>
		</div>

		<div id="newsHead">
		<h3>Latest News</h3>
				
		<?php
		require_once('fry/banana.php');
		$db_server= mysqli_connect($db_hostname,$db_username,$db_password, $db_database);
		if(!db_server)
			die ("unable to connect to MySQL" .mysqli_error());


		$query="SELECT * FROM newsContent ORDER BY newsId DESC";
		$results = mysqli_query($db_server,$query);
		$iter = 0;
		while($row=mysqli_fetch_array($results) and $iter < 9)
		{	
			echo '<div class="newsBox">
			';
			print("<h4>$row[date]</h4>  <p>$row[content]</p>");
			echo '<div class ="newsAuth">';
			print ("<p>-$row[author]</p>");
			echo '</div>';
			echo '</div>
			';
			$iter++;
		}
		mysqli_close($db_server);
		?>
			<div id="archive">
				<p><a href="archive.php">Archive</a></p>
			</div>
		</div>
		
		<div id="twitter">
		<a class="twitter-timeline" data-dnt="true" href="https://twitter.com/Jstdlib" data-widget-id="385136524347441152">Tweets by @Jstdlib</a>
		<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id))
		{js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}
		(document,"script","twitter-wjs");</script>
	    </div>
		
		
		
		<!-- FOOTER -->
		<?php include "headnavfoot/footer.php"; ?>

</div>
</body></html>