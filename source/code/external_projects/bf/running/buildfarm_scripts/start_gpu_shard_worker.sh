#!/bin/bash
cd ~/Desktop/bazel-buildfarm;
sleep 4;
printf "\e]2;GPU WORKER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-shard-worker ~/Desktop/unilang/source/code/external_projects/bf/running/configs/shard-gpu-worker.config.example
read;
