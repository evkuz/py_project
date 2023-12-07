#!/bin/bash

STATDATA="statData.txt"
SCRIPT="calibration.py"
START=$(date)

cp /dev/null $STATDATA
numOfCycles=15
n=0
while [ $n -le $numOfCycles ]
do
 echo "current bash cycle is ${n}"
 python  $SCRIPT
 sleep 1 
 n=$((n+1))
done
FINISH=$(date)
echo "Started at $START"
echo "Finished at $FINISH"
