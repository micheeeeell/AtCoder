#!/bin/bash
file_end=$1
if [ -z $file_end ]; then
    echo "終了条件がないからF入れといたよ"
    file_end='F'
fi
string="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in {0..25}; do
    # echo ${file_name}
    file_name=${string:i:1}
    if [ -e ${file_name}.cpp ]; then
        if [ $file_name = $file_end ]; then
            break
        fi
        continue
    fi
    cat ~/win/atcoder/ShellScripts/template.cpp > ${file_name}.cpp
    echo "$file_name.cpp was made."
    if [ $file_name = $file_end ]; then
        break
    fi
done