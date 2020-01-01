the network connections made when performing a build
a better version of:
strace -f -e trace=network ./build_everything 2>&1 | grep sin_addr

good to check that every network call is coming from trusted and controlled sources within an org