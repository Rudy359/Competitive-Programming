#!/bin/bash

g++ -std=gnu++17 -O2 -pipe -static -o main main.cpp -D LOCAL_DEFINE
g++ -std=gnu++17 -O2 -pipe -static -o brute brute.cpp -D LOCAL_DEFINE
g++ -std=gnu++17 -O2 -pipe -static -o gen gen.cpp

for i in {1..100}
do
    printf $i
    printf '\n'
    ./gen > input.in
    ./main < input.in > output.out 
    ./brute < input.in > output2.out
    if cmp -s "output.out" "output2.out"; then
        printf 'OK\n'
    else
        printf 'WA\n'
        cat input.in
        break
    fi
done