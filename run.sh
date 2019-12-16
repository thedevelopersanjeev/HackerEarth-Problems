#!/bin/bash

# simple bash script to compile and run c++ program
g++ -std=c++17 -Wall -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -g main.cpp -o main
./main 
exit 0
