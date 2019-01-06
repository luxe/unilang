FROM ubuntu:14.04

RUN apt-get update
RUN apt-get install -y git patch python wget

WORKDIR /unilang
VOLUME /cache
