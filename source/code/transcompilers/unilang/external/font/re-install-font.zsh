#!/usr/bin/env zsh

#this is what I must do on Ubuntu to refresh the font.

#delete existing font
echo "deleting font..."
rm -rf ~/.local/share/fonts/*
rm -rf ~/.fonts/*

#I don't think this is necessary, but I'm use to seeing the
#font change to a fallback, before I load in the new font file
#echo "waiting 10 seconds..."
#sleep 10;
#(seeing the fallback does not happen anymore)

# normally I double click the font file, and it has a button to install.
# as far as I can tell, that just copies the font into a particular directory
# we will do that automatically.

#on my old machine it was ~/.local/share/fonts/;
#on my new machine, its apparently ~/.fonts
#It's apparently set via /etc/fonts/fonts.conf
#not sure why it changed... we'll just put it in both places for now
echo "loading new font file..."
mkdir -p ~/.local/share/fonts/;
mkdir -p ~/.fonts/;
cp -f font-files/ProFontMedium-11.bdf ~/.local/share/fonts/;
cp -f font-files/ProFontMedium-11.bdf ~/.fonts/;

#I've had it get stuck on the fallback font...
#hmm.. I dunno.  run the script again.  worked for me.
#you know what, we'll force the registry changes, even though they shouldn't be changing
sudo gsettings set org.gnome.desktop.interface document-font-name 'ProFont 8'
sudo gsettings set org.gnome.desktop.interface font-name 'ProFont 8'
sudo gsettings set org.gnome.desktop.interface monospace-font-name 'ProFont 8'
sudo gsettings set org.gnome.nautilus.desktop font 'ProFont 8'
sudo gconftool --set /apps/metacity/general/titlebar_font 'ProFont 8' --type STRING
