#!/bin/bash
printf "\e]2;redis\a"

#make sure redis is downloaded
if [ ! -d ~/Desktop ]; then
	git clone git@github.com:redis/redis.git ~/Desktop/redis
fi

#and configured properly
sed -i 's/30000/6378/g' ~/Desktop/redis/utils/create-cluster/create-cluster

#use their create cluster script
cd ~/Desktop/redis/utils/create-cluster/
./create-cluster start
./create-cluster create
redis-cli -c -p 6379 FLUSHALL
redis-cli -c -p 6380 FLUSHALL
redis-cli -c -p 6381 FLUSHALL
redis-cli -c -p 6382 FLUSHALL
redis-cli -c -p 6383 FLUSHALL
redis-cli -c -p 6384 FLUSHALL
read;
