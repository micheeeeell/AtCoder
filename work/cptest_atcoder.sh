#!/bin/bash
problemname=$1
oj login -u micheeeeell -p 10michell01 "https://atcoder.jp/"
oj login --check "https://atcoder.jp/"
oj dl "https://${problemname:0:6}.contest.atcoder.jp/tasks/${problemname:0:8}"
g++ -Wall -std=c++14 ./${problemname:7:8}.cpp
oj test
rm -f a.out
rm -rf test 