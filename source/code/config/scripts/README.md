# scripts-install
installs shell scripts


##SSH install
```
mkdir -p ~/.bin; #make sure the bin folder already exists \
rm -rf ~/.bin/scripts; #delete what is already there \
git clone git@github.com:system-configuration/scripts-install.git ~/.bin/scripts; #clone into it \
chmod -R 777 ~/.bin/scripts; #make sure we have permission to run all the scripts
```
##HTTPS install
```
mkdir -p ~/.bin; #make sure the bin folder already exists \
rm -rf ~/.bin/scripts; #delete what is already there \
git clone https://github.com/system-configuration/my-scripts-install.git ~/.bin/scripts; #clone into it \
chmod -R 777 ~/.bin/scripts; #make sure we have permission to run all the scripts
```

# notes about all these scripts:
personally, it would be better to have these written in c++ and made an actual binary
instead of bash or zsh.  So maybe a long term goal will be to convert these scripts to be built
inside a mono-repo.  We will remain support for making quick scripts to do things.