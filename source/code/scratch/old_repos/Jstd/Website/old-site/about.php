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
	
	<div id="pageText">
	<h2>The J Standard Origin</h2>
	<p>The J Standard started while Joshua was taking his second level programming class at Edinboro University. He found that 
	he was writing the same functions over and over again. He began to try to take those functions out into a seperatie file
	so he would not have to re-write them ever again. In his third level programming class, he learned about namespaces and 
	more about libraries. Thus, the J Standard had begun.
	</p>
	</div>
	
		
		<!-- FOOTER -->
		<?php include "headnavfoot/footer.php"; ?>

</div>
</body></html>