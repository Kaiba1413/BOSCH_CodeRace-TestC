#!/bin/bash
# A sample Bash script to catch the warning from Sec Scanning Tool
# It can be extended to handle different outputs from cppcheck
echo Start Processing Sec Scanning Output
if [ $? -eq 0 ]
then 
  exit 1
elif [ $? -eq "0"]
then 
  exit 1
else
  echo $?
  echo no vulnerabilities
fi

