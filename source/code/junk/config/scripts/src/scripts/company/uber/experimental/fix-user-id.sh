#!/usr/bin/env zsh

#make sure you are part of the uberatc group
sudo usermod -a -G uberatc thickey

#make sure uberatc is your primary group
sudo usermod -g uberatc thickey

#sudo groupmod -g 17143 thickey

#change uid (this needs to be done from the account you are not in)
sudo usermod -u 17143 thickey