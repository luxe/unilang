<?php

$menu = array (
		'home' => array ('text'=>'Home', 'url'=>'/default.php'),
		'about' => array ('text'=>'About', 'url'=>'/about.php'),
		'files' => array ('text'=>'Files', 'url'=>'/files.php'),
		'docs' => array ('text'=>'Documentation', 'url'=>'/doc.php'),
		'blog' => array ('text'=>'Blog', 'url'=>'http://jstdlib.tumblr.com'),
		'suggest' => array ('text'=>'Suggestions', 'url'=>'/suggest.php'),
		'contact' => array ('text'=>'Contact', 'url'=>'/contact.php')
		);

$subMenu = array (
	'functions' => array ('text'=>'Functions', 'url'=>'/func/func.php'),
	'types' => array ('text'=>'Types', 'url'=>'/types/types.php'),
	'constants' => array ('text'=>'Constants', 'url'=>'/const/const.php')
);


class Navigation
{
	
	public static function GenerateMenu($items)
	{
		$html = "<nav class = 'navBar'>\n";
		foreach($items as $item)
		{
			$html .= "<a href='{$item['url']}'>{$item['text']}</a>\n";
		}
		$html .="</nav>\n";
		return $html;
	}
	public static function GenerateSubMenu($items)
	{
		$html ="<div id ='doc-subNav'><ul>\n";
		foreach($items as $item)
		{
			$html .= "<li><a href='{$item['url']}'>{$item['text']}</a></li>\n";
		}
		$html .= "</ul></div>\n";
		return $html;
	}
};

?>
