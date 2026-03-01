#!/bin/bash

# launch_hotrace <input_file>
# Runs `./hotrace` 10 times in an inner loop, repeats that 10 times,
# measures elapsed time for each outer iteration and prints the average.
launch_hotrace ()
{
    if [ -z "$1" ]; then
        echo "Usage: $0 <input_file>"
        return 1
    fi

    total=0
    runs=0

    for j in {1..1}; do
        start=$(date +%s.%N)
        for i in {1..10}; do
            ./hotrace < "$1" >/dev/null
        done
        end=$(date +%s.%N)
        # compute elapsed = end - start
        elapsed=$(awk -v s="$start" -v e="$end" 'BEGIN{printf "%.6f", e - s}')
        total=$(awk -v a="$total" -v b="$elapsed" 'BEGIN{printf "%.6f", a + b}')
        runs=$((runs + 1))
    done

    awk -v s="$total" -v n="$runs" 'BEGIN{if(n>0) printf "Average total: %.6f seconds\n", s / n; else print "No runs"}'
}
