#!/bin/bash
problemurl=$1
problemname=$2
export $(cat ~/gitwork/AtCoder/ShellScripts/.env | xargs);
echo $USERNAME
echo $PASS
oj login -u $USERNAME -p $PASS "https://atcoder.jp/"
# oj login --check "https://atcoder.jp/"
oj dl $problemurl
g++ -std=c++17 -ftrapv -g ./${problemname}.cpp
oj test
# rm -f a.out
rm -rf test 