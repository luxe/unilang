FROM ubuntu:14.04

# I'd like to build all of these from source, but that's not always easy to do in bazel.
# From Cmake to autotools; we live in a world of exotic builds and difficult to pin dependencies.
# So this docker container is a fact of life.
# As an aspiration, we want to migrate as many package manager-related actions into build rules.
RUN apt-get update
RUN apt-get install -y git
RUN apt-get install -y patch
RUN apt-get install -y python
RUN apt-get install -y wget
RUN apt-get install -y m4
RUN apt-get install -y libgmp-dev
RUN apt-get install -y libgmp3-dev
RUN apt-get install -y xorg
RUN apt-get install -y libsdl2-dev
RUN locale-gen en_US en_US.UTF-8
RUN dpkg-reconfigure locales
RUN env LANG=en_US.UTF-8
RUN export LC_ALL=$LANG

# Copy the content of your repository into the image
COPY . ./
