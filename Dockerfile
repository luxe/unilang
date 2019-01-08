FROM ubuntu:14.04

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y patch
RUN apt-get install -y python
RUN apt-get install -y wget

WORKDIR /unilang
VOLUME /cache
