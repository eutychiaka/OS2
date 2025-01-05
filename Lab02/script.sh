#!/bin/bash


date

current_time=$(date +%s)
echo "$current_time"
let current_time=current_time+current_time
echo "$current_time"
echo "current time in seconds: $current_time"

echo "current time *2: $double_time"

for i in {1..20}; do
    echo "number: $i"
done

