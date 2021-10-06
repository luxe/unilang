#hcp and repo structure reverser
git clone git@github.com:luxe/electrical-system.git
cd electrical-system;
git-it --all
cd project/src/;
make;
generative-dependency-symbolic-resolver;
hcp-file-resolver;
make clean;
clang-format-3.6 -i *.cpp *.hpp;
