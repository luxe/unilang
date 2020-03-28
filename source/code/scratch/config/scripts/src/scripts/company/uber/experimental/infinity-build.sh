#!/usr/bin/env zsh

#run this script as root.  
#It was working for me previously without root, 
#but all of a sudden, it started printing this warning on inotifywait start:  

#```
#Couldn't initialize inotify.  Are you running Linux 2.6.13 or later, and was the
#CONFIG_INOTIFY option enabled when your kernel was compiled?  If so, 
#something mysterious has gone wrong.  Please e-mail radu.voicilas@gmail.com
# and mention that you saw this message.
#```

#Weird.  Running as root seems to fix it.
#The config files for inotifywait can be found here:
#/proc/sys/fs/inotify/max_user_*


#
#If you like to make your limit permanent, use:
#$ echo fs.inotify.max_user_watches=524288 | sudo tee -a /etc/sysctl.conf
#$ sudo sysctl -p

while inotifywait -qqr -e modify ~/Desktop/av/source; do
	clear;
	cd ~/Desktop/b;
	./bops build //...:all;
	echo "DONE!";
done