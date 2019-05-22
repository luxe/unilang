
# Why does this docker container exist?
# I'd like to build everything from source, but that's not always easy.
# From Cmake to autotools; the world is full of exotic builds and difficult to pin-down dependencies.
# For non-bazel projects, I usually have to rewrite the tool's build files in skylark.
# This can be difficult.  For example, when build files generate other build files for the build.
# We use the docker container when we can't figure out how to build from source.
# As an aspiration, I'd want to migrate as many package manager-related actions into the build rules.
# But if it's too hard, they can stay here.
# It's also nice to have Dockerfiles for CIs and containerized contexts for different tools.

# Other thoughts on reducing the Dockerfile:
# I think there is a way to include debian packages directly in bazel rules.  We could look into that.
# Although its a better practice to run all of these commands a a single command since it will create less layers,
# I'm keeping them separated as it makes debugging easier.

# We try to upgrade to the latest Ubuntu when available
FROM ubuntu:18.04

# All of the necessary apt-get installs
# Strangely, wget was not working on a different machine??
# Which is confusing because I was building a docker container; why would the host machine matter.
# The fix was to use --fix-missing on the update.
# With the transition from Ubuntu 14.04 to 18.04, installing xorg would pause for user input on country
# This has been mitigated using the "noninteractive".
RUN apt-get update --fix-missing
RUN apt-get install -y git
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
RUN apt-get install -y libxdo-dev

# packages we may or may not need
# RUN apt-get install -y git-lfs
# RUN apt-get install -y openjdk-8-jdk

# The build runs certain tools that need a particular locale to be available
# I had to do this differently when transitioning from Ubuntu 14.04 to 18.04
# This will ensure the en_US.UTF-8 locale is available.
# Ideally, I'd like to fix the tools so this is not needed in the Dockerfile.
RUN echo "locales locales/default_environment_locale select en_US.UTF-8" | debconf-set-selections
RUN echo "locales locales/locales_to_be_generated multiselect en_US.UTF-8 UTF-8" | debconf-set-selections
RUN rm "/etc/locale.gen"
RUN dpkg-reconfigure --frontend noninteractive locales

# Copy the content of your repository into the image
COPY . ./
