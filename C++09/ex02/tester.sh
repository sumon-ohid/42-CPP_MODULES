#!/bin/bash

# for i in $(seq 1 1000); do
#     n=$i
#     random_numbers=$(shuf -i 1-100000 -n $n | tr "\n" " ")
#         output=$(./PmergeMe $random_numbers)
    
#     if echo "$output" | grep -q "Array is not sorted"; then
#         echo "Array is not sorted. Stopping the loop."
#         break
#     fi
#     echo -e "\e[1;32mTest $i passed\e[0m"
# done


for i in $(seq 1 3000); do
    n=$i
    random_numbers=$(shuf -i 1-100000 -n $n | tr "\n" " ")
     ./PmergeMe $random_numbers
done
