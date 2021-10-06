#!/bin/bash


attempt-to-lock() {
    exec 200>/var/lock/.myscript.exclusivelock
    flock --nonblock 200;
}

attempt-to-lock-with-a-time-out() {
    exec 200>/var/lock/.myscript.exclusivelock
    flock --wait $1 200;
}



main() {
  attempt-to-lock;
  
  #If we can't get the lock
  if (($? > 0)); then
    echo "The script is already being run.";
    echo "We will wait a half hour at most for the script to finish.";
    
    attempt-to-lock-with-a-time-out 1800;
    if (($? > 0)); then
      
    fi
    
  fi
  
  
  
  sleep 10;
}

main



#get mutex name
#scriptname=$(basename $0)
#lock="/var/run/${scriptname}"
 
#open mutex and set the file handle to 200
#exec 200>$lock;

#flock -n 200;

#if [ $? ]; then
#  echo "good"
#else
#  echo "bad";
#fi

#sleep 60;
#echo "all done";
#exit;
 
## The code:
#pid=$$
#echo $pid 1>&200
#echo "Hello world"
#sleep 60
#echo "Goodbye world"
