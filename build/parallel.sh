#!/bin/bash

echo "" > resultats.txt

./tp5_mc MTStatus1 >> resultats.txt &
./tp5_mc MTStatus2 >> resultats.txt &
./tp5_mc MTStatus3 >> resultats.txt &
./tp5_mc MTStatus4 >> resultats.txt &
./tp5_mc MTStatus5 >> resultats.txt &
./tp5_mc MTStatus6 >> resultats.txt &
./tp5_mc MTStatus7 >> resultats.txt &
./tp5_mc MTStatus8 >> resultats.txt &
./tp5_mc MTStatus9 >> resultats.txt &
./tp5_mc MTStatus10 >> resultats.txt &

wait

awk '{s+=$1}END{printf "Moyenne des estimation de PI : %1.10f\n", s/(NR-1)}' resultats.txt
