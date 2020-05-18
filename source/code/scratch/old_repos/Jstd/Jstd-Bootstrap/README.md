jstd-bootstrap
==============

bootstraps the tools needed to build and use The Jstd

###HOW DO I INSTALL?
Here. Copy-paste this to download and install everything:  
```
rm -rf ~/.github; mkdir -p ~/.github; \
rm -rf jstd-bootstrap-temp; \
mkdir jstd-bootstrap-temp; cd jstd-bootstrap-temp; \
git clone git@github.com:Jstd/jstd-bootstrap.git; \
cd jstd-bootstrap; \
./install; cd ../../; rm -rf jstd-bootstrap-temp
```

###WHAT GET INSTALLED?
The bootstrap installs the following programs:

| Program       | Description   |
| ------------- |:-------------:|
| git-it        | c++ dependency manager |
| hcp-compiler  | converts .hcp files into .cpp and .hpp |
| ls-cpp        | like the `ls` program but has useful filters |
| hcp-touch     | like the `touch` program but is useful for starting .hcp files |
They get added in the following order:
```
1. hcp-compiler (bootstrap version)
2. git-it  (bootstrap version)
3. hcp-compiler
4. git-it
5. ls-cpp
6. hcp-touch
```

various generative dependencies are also installed.  
Two folders will be created/changed:

| Folder       | Description   |
| -------------|:-------------:|
| ~/.github/   | will contain copies of various repos from github |
| ~/.bin/      | will contain the binaries for the programs listed above |
