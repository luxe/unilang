#!dockerfile-shebang.sh
FROM ubuntu:16.04
RUN apt-get update
RUN apt-get install -y software-properties-common
RUN apt-get install -y gcc
RUN apt-get install -y g++
ENTRYPOINT ["/usr/bin/ldd", "--version"]