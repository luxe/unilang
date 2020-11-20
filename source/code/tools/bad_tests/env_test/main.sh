#!/bin/bash
env
if [ "$TESTVAR" = "foobar" ]
then
    exit 0;
fi

exit -1;