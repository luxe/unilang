#!/bin/bash
sudo add-apt-repository http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv F60F4B3D7FA2AF80

sudo apt-get install cuda-cuobjdump-11.0
sudo apt-get install cuda-nvprune-11.0
sudo apt-get install cuda-nvdisasm-11.0