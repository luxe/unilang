FROM ubuntu:14.04

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y patch
RUN apt-get install -y python
RUN apt-get install -y wget
RUN apt-get install -y m4
RUN apt-get install -y libgmp3-dev

# Copy the content of your repository into the image
COPY . ./

WORKDIR /unilang
VOLUME /cache
