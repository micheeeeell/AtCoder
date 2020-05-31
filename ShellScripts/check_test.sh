#!/bin/bash
problem=$1
g++ -std=c++17 -ftrapv -g -D LOCAL ./${problem}.cpp
echo "テストケースを入力してください"
./a.out
