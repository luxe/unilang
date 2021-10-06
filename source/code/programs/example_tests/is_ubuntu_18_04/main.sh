#!/bin/bash
cat /etc/os-release | grep "Ubuntu 18.04" 2>&1 > /dev/null
if [ $? -eq 0 ]
then
  echo "This test ran on Ubuntu 18.04"
  exit 0
fi
echo "This test DID NOT run on Ubuntu 18.04"
exit -1