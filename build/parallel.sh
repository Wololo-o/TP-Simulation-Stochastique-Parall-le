#!/bin/bash

echo "" > resultats.txt

./estimationPI MTStatus1 >> resultats.txt &
./estimationPI MTStatus2 >> resultats.txt &
./estimationPI MTStatus3 >> resultats.txt &
./estimationPI MTStatus4 >> resultats.txt &
./estimationPI MTStatus5 >> resultats.txt &
./estimationPI MTStatus6 >> resultats.txt &
./estimationPI MTStatus7 >> resultats.txt &
./estimationPI MTStatus8 >> resultats.txt &
./estimationPI MTStatus9 >> resultats.txt &
./estimationPI MTStatus10 >> resultats.txt &

wait

awk '{s+=$1}END{printf "Moyenne des estimation de PI : %1.10f\n", s/(NR-1)}' resultats.txt
