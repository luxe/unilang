<!DOCTYPE html>

<html>
<head>
	 <?php include '../headnavfoot/head_data.php'; ?>	
<title>   jstd Library </title>

</head>

<body>
<div id="wrapper">
    <div id="header">
    
      <!--header -->
      <?php include '../headnavfoot/header.php'; ?>
      
      <!-- Navigation Bar -->
      <?php include '../headnavfoot/navigation.php'; ?>
      <?php echo Navigation::GenerateMenu($menu); ?>
		  
    </div>
    
      <!-- sub menu -->
    <?php echo Navigation::GenerateSubMenu($subMenu); ?>

    <div id="pageText">
    <h2>const landing page!</h2>
      <div id="treeContent">
	<?php
	    
	  if ($_GET['title'] =="")
	    {
	    }
	  else
	    {
	      echo '<h1>HI!</hi>';
	    }
	  ?>
      </div>
    </div>
    
	    
      <!-- FOOTER -->
      <?php include "../headnavfoot/footer.php"; ?>

</div>
</body></html>