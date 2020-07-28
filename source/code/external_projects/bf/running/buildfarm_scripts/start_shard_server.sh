#!/bin/bash
cd ~/Desktop/bazel-buildfarm;
sleep 3;
printf "\e]2;SERVER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-server $PWD/examples/shard-server.config.example
read;
