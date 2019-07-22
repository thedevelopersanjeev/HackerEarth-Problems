#!/bin/bash

# simple bash script to compile and run c++ program
g++ -std=c++17 -O1 -Wall -g main.cpp -o main
./main 
exit 0
