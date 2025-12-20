#!/bin/bash

COUNT=0
TOTAL=0
STATE="PASS"

while [ $COUNT -lt 50 ]
do
    ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')

    PUSH_OUTPUT=$(./push_swap $ARG)

    CHECKER_RESULT=$(echo "$PUSH_OUTPUT" | ./checker $ARG)

    OPS=$(echo "$PUSH_OUTPUT" | wc -l)

    if [ "$OPS" -gt 5500 ]; then (STATE="FAILED") else (STATE="PASS") fi

    echo "TEST $COUNT -> $OPS ops | $STATE | checker = $CHECKER_RESULT"

    TOTAL=$((TOTAL + OPS))
    COUNT=$((COUNT + 1))
done

TOTAL=$((TOTAL / 50))
echo "Average operations = $TOTAL"
