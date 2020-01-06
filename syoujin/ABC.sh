#!/bin/bash

for f in *.cpp
do
name=${f%.*}
# echo ${f##*.}
k=${f##*.}
# if [ ${f} = "ABC006C.cpp" ]; then
#     # echo $k
#     # echo ${f}
#     mkdir test
#     mv ${f} /mnt/c/gitwork/atcoder/syoujin/test/
# fi
# echo ${name:0:3}
if [ ${name:0:3} = "ABC" ] ; then
    # echo ${name:3:3}
    if [ ! -e /mnt/c/gitwork/atcoder/ABC/ABC${name:3:3} ]; then
        mkdir /mnt/c/gitwork/atcoder/ABC/ABC${name:3:3}
    fi
    mv ${f} /mnt/c/gitwork/atcoder/ABC/ABC${name:3:3}/
elif [ ${name:0:3} = "AGC" ] ; then
    # echo ng
    if [ ! -e /mnt/c/gitwork/atcoder/AGC/AGC${name:3:3} ]; then
        mkdir /mnt/c/gitwork/atcoder/AGC/AGC${name:3:3}
    fi
    mv ${f} /mnt/c/gitwork/atcoder/AGC/AGC${name:3:3}/
elif [ ${name:0:3} = "ARC" ] ; then
    # echo arc
    if [ ! -e /mnt/c/gitwork/atcoder/ARC/ARC${name:3:3} ]; then
        mkdir /mnt/c/gitwork/atcoder/ARC/ARC${name:3:3}
    fi
    mv ${f} /mnt/c/gitwork/atcoder/ARC/ARC${name:3:3}/
fi
done