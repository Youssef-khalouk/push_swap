#!/bin/bash

COUNT=0
TOTAL=0
STATE="PASS"

while [ $COUNT -lt 50 ]
do
    ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    if [ "$OPS" -gt 5500 ]; then STATE="FAILED"; else STATE="PASS"; fi
    echo TEST $COUNT "->" $OPS $STATE 
    TOTAL=$((TOTAL + OPS))
    COUNT=$((COUNT + 1))
done
TOTAL=$((TOTAL / 50))
echo total  =  $TOTAL