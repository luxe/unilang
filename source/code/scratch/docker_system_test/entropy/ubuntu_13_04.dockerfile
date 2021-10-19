#!dockerfile-shebang.sh
FROM salttest/ubuntu-13.04:latest
ENTRYPOINT ["cat /proc/sys/kernel/random/entropy_avail"]