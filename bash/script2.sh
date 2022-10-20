#bin/bash

index=1
j=$#
while [ $index -le $j ]
do
    echo "$index : $1"
    index=$((index+1))
    shift 1
done