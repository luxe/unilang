# ubuntu-right-click-options
settings for custom configured right-click options  

#Non-automated changes to make:  
Edit->Preferences->Runtime preferences
Turn off "Create a root 'Nautilus-Actions' menu

Edit->Preferences->Runtime Execution
use: gnome-terminal --command COMMAND
*make sure the update command doesn't have a semicolon
*make sure you put in the actual home directory name (couldn't find a way to automate this)

#Creating and Using:  
For Ubuntu, it seems that the best way to customize a right-click menu is through
`nautilus-actions-config-tool`.  

I do my customizations there, and export them.  
This repo contains the export, that you can import.  

#Importing
Tools->Import Assistant

#Exporting
Tools->Export Assistant

#Other Info:
Attached is a dump of nautilius related files on my system.
Also, this file:  
/etc/xdg/autostart/nautilus-autostart.desktop
