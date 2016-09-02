#!/bin/sh

i=0
team=$1
nb=$2

if [ -f $team ] ;
then
    echo "./run.sh team_nb"
else
    while (($i < $nb));
    do
	./lemipc . $team &
	i=$(expr $i + 1)
	usleep 50000
    done
fi
