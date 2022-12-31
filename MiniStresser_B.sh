#!/bin/bash

SERVERID=$(ps | grep server_bonus | awk 'NR == 1{print $2}')
PROCCESS=$(top -l 1 | grep client_bonus | wc -l | tr -d ' ')
for i in {1..100000}
do
	if [ $PROCCESS -eq 0 ]
	then
		./client_bonus 55354 💔
	else
		kill -1 $(top -l 1 | grep client_bonus | awk '{print $1}')
	fi
done
