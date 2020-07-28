#!/bin/bash
cd ~/Desktop/bazel-buildfarm;
sleep 4;
printf "\e]2;CPU WORKER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-shard-worker ~/Desktop/unilang/source/code/external_projects/bf/running/configs/shard-cpu-worker.config.example
read;
