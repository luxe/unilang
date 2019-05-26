#!/usr/bin/env zsh
# This is a script I run every morning to get things situated.
# Its also useful to run if I restart my machine

# do we need to fix anything with gnome?  
# gnome has been flaky for me, and the menu bar hasn't been appearing
# sometimes this command fixes it, other times, it crashes the whole desktop and logs me out
# maybe we should switch to Xubuntu... I'd have to experiment and see if the environment 
# is as comfortable as gnome.

#Ensure we have the right Wifi
#UGuest: Drive4Uber

#System Stability
update-uber-packages
    
#Build System Maintenance
fix-build-cache-server

#sometimes you need to clean your git directories
#rebuild a repo
cd ~/Desktop/1/;
git stash;
./bops build clean;
git clean -xfd
git gc --aggressive;
./bops build //...:all;

#File Access
mount-all-uber-drives

#Workflow
#----------------
#make sure rtags is running for code completion
#rtags was not working for me in sublime.  I stopped using it.
#nice ionice -c idle rdm -j6

#so the the autofix linter doesn't time out
#this doesn't preserve when you close the terminal
export LINT_TIMEOUT=0

#make sure the code base is up to date
git pull;
./bops build //...:all;

#get rolling and quit

./bops data_collection start

#see changes
./bin/xlogdump  /mnt/logs/YELLOW/av/2017.09/2017.09.07/KRYPTON0089/15.39.54_trevor_lossless2/TransmissionTimeIndex00000.hlog  -c /hdcam/10_port_front_roof_wide/image   | grep last_

#see time ranges
./bin/xlogdump -d /mnt/logs/YELLOW/av/2017.09/2017.09.07/KRYPTON0089/15.39.54_trevor_lossless2/TransmissionTimeIndex00000.hlog



#you probably have multiple ssh-agents running
#killall ssh-agent, and eval $(ssh-agent), and re-add avos_key manually

#in case you want to deploy a car.
#ssh keys expire after a few days. Might as well auto-refresh
./bops setup_ssh

#in case you need to re-sync a context
#you have to remember to rebuild any changes, otherwise the cluster won't see it
#then you need to do the resync.  To avoid forgetting one of these steps, we
#would want to run them together:
./bops build //...:all;                    
./cops --cluster CORNDOG mount_context thickey_17_212_0                      
./cops --cluster HAMBURGER sync_context_in_parallel thickey_17_212_0 &;
./cops --cluster CORNDOG sync_context_in_parallel thickey_17_212_0 &;

source/mlp/tools/airflow-mlp/scripts/trigger-dag.sh trigger_nightly_map_build

#Personal Comfort
#----------------
# Now that we have a loaded desktop,
# we'll start by setting the screen tint to what you are initially comfortable with by default
eyes-normal

#add tiger oneko (so you're not lonely)
spawn-tiger

#clear font cache? (i dunno)
fc-cache -rv