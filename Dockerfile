FROM ubuntu:14.04
#FROM ubuntu:18.04

# I'd like to build all of these from source, but that's not always easy in bazel.
# From Cmake to autotools; we live in a world of exotic builds with difficult to pin-down dependencies.
# We usually have to rewrite the tool's build files in skylark, and sometimes the build files generate other files for the build.
# So this docker container is a shortcut when we can't figure out how to build from source.
# As an aspiration, we want to migrate as many package manager-related actions into build rules.
# But if it's too hard, they can stay here.
# Also consider including debian packages directly in bazel rules (something to look into)?
# We should do all of these installs as a single command.  
# It will create less docker layers and its a better practice
RUN apt-get update
RUN apt-get install -y git
#RUN apt-get install -y git-lfs
#RUN apt-get install -y openjdk-8-jdk
RUN apt-get install -y patch
RUN apt-get install -y python
RUN apt-get install -y zip
RUN apt-get install -y wget
RUN apt-get install -y m4
RUN apt-get install -y libgmp-dev
RUN apt-get install -y libgmp3-dev
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y xorg
RUN apt-get install -y libsdl2-dev
RUN apt-get install -y libsfml-dev
RUN apt-get install -y libsdl2-image-dev
RUN apt-get install -y libsdl2-image-2.0-0
RUN apt-get install -y locales

# Language Locals.
# I should fix this in the tools that need them.
# For now, In order to get the CIs to pass, we will force it like this.
# Yeah, I don't know what the hell is going with all this UTF stuff.  
# I'm just trying to get CIs to pass.  It works in ubuntu 14 but not 18.
RUN echo "nb_NO.UTF-8 UTF-8" >> /etc/locale.gen
RUN echo "en_US.UTF-8 UTF-8" >> /etc/locale.gen
RUN locale-gen "en_US"
RUN locale-gen "en_US.UTF-8"
RUN dpkg-reconfigure locales
RUN env LANG=en_US.UTF-8
RUN export LC_ALL="en_US.UTF-8"
RUN export LANG="en_US.UTF-8"
#RUN update-locale LANG="en_US.UTF-8"

# Copy the content of your repository into the image
COPY . ./
