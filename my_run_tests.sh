#!/usr/bin/env bash

for i in tests/*.cpp ;do
    echo $i
    name=$(basename $i)
    g++ -std=c++11 $i -o "output/$name.out"
    ./output/$name.out
done