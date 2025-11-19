#!/bin/bash
for i in $(seq 0 25 500); do
    seq -9999 9999 | shuf -n $i > args.txt
    args=$(cat args.txt)
    ./push_swap --medium $args > ops.txt
    ops=$(wc -l ops.txt | awk '{print $1}')
	echo "$i $ops"
done
