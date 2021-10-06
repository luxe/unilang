#!/bin/bash
cat /etc/os-release | grep "Ubuntu 20" 2>&1 > /dev/null
if [ $? -eq 0 ]
then
  echo "This test ran on Ubuntu 20"
  exit 0
fi
echo "This test DID NOT run on Ubuntu 20"
exit -1