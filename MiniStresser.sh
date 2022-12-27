#!/bin/bash

SERVERID=$(ps | grep server | awk 'NR == 1{print $1}')
PROCCESS=$(top -l 1 | grep client | wc -l | tr -d ' ')
for i in {1..100000}
do
	if [ $PROCCESS -eq 0 ]
	then
		./client $SERVERID "Wydad AC"
	else
		kill -1 $(top -l 1 | grep client | awk '{print $1}')
	fi
done
