#!/bin/bash
cd ~/Desktop/bazel-buildfarm;
printf "\e]2;server\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-server $PWD/examples/server.config.example
read;
