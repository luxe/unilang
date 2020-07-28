#!/bin/bash
cd ~/Desktop/bazel-buildfarm;
sleep 3;
printf "\e]2;SERVER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-server ~/Desktop/unilang/source/code/external_projects/bf/running/configs/shard-server.config.example
read;
