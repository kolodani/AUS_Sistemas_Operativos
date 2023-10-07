#!/bin/bash

for n in $(seq 1 1000)
do
    out=""
    [ $((n%3)) -eq 0 ] && out="Fizz"
    [ $((n%5)) -eq 0 ] && out="${out}Buzz"
    echo -n ${out:-$n}; echo -n " "
done
