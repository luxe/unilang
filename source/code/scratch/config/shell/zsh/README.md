# zsh-configuration
configuration for zsh
installs zsh shell
installs oh-my-zsh framework
installs all the custom configurations
attempts to make zsh the default shell (probably requires reboot)

```
cd ~/Desktop; \
sudo apt-get install -y curl; \
sudo apt-get install -y zsh; \
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"; \
git clone git@github.com:system-configuration/zsh-configuration.git; \
cd zsh-configuration/project/src/; \
rm -rf ~/.zshrc; \
cp -f .zshrc ~/; \
rm -rf ~/.oh-my-zsh/custom; \
cp -rf custom ~/.oh-my-zsh/; \
cd ../../../; \
rm -rf zsh-configuration; \
mkdir -p ~/.bin/scripts; \
chsh -s $(which zsh);
```
