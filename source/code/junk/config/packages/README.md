##Ubuntu Post Install Script  
If you download, simply run it like this:   
`sudo ./configure; ./configure`  
the first command does everything needed as sudo, and running it again without sudo completes user specific tasks that wouldn't work correctly with sudo.
... so you gotta run both.

##One liner (do everything)
```
sudo apt-get install -y --force-yes --fix-missing git; \
sudo apt-get install -y --force-yes --fix-missing xclip; \
git clone git@github.com:system-configuration/ubuntu-post-install.git; \
cd ubuntu-post-install/project/src; \
sudo ./configure; \
./configure;
```
