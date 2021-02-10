#! /bin/bash

# 第一种方式
## grep 带行号输出, 过滤第10行，去掉行号，不是很友好的样子
echo "func1: "
grep -n "" file.txt | grep -w '^10' | cut -d: -f2

# 第二种方式
echo "func2: "
sed -n '10p' file.txt

# 第三种方式
echo "func2: "
awk '{if(NR==10){print $0}}' file.txt