#!/bin/bash
for f in ./*.ogg
do
    temp=${f##*/} # 不含路径的文件全称
    temp=${temp%%.*} # 文件名
    ffmpeg -i $f -f wav ./$temp.wav
done
