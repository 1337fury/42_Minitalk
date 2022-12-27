#!/bin/bash

SERVERID=$(ps | grep server_bonus | awk 'NR == 1{print $1}')
PROCCESS=$(top -l 1 | grep client_bonus | wc -l | tr -d ' ')
for i in {1..100000}
do
	if [ $PROCCESS -eq 0 ]
	then
		echo $(./client_bonus $SERVERID 💔)
	else
		kill -1 $(top -l 1 | grep client_bonus | awk '{print $1}')
	fi
done
