FROM ubuntu:14.04

RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y patch
RUN apt-get install -y python
RUN apt-get install -y wget
RUN apt-get install -y m4
RUN apt-get install -y libgmp3-dev
RUN locale-gen en_US en_US.UTF-8
RUN dpkg-reconfigure locales
RUN env LANG=en_US.UTF-8
RUN export LC_ALL=$LANG

# Copy the content of your repository into the image
COPY . ./
