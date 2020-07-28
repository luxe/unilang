#!/bin/bash
cd ~/Desktop/bazel-buildfarm;
sleep 3;
printf "\e]2;CPU WORKER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-operationqueue-worker $PWD/examples/worker.config.example
read;
