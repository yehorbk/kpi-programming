#!/bin/bash

n=5 # items count
backpackVolume=16 # backpack volume
weights=(3 5 7 9 4) # weights array
values=(24 12 68 43 32) # values array

maxValue=0
result=()

function updateIfAmountGreater {
    if [ $amount -gt $maxValue ]
    then
        maxValue=$amount
        result=("${array[@]}")
    fi    
}

function fillBackpack {
    for (( i = $1; i < n; i++ ))
    do
        weight=${weights[i]}
        amount=${values[i]}
        array=(${weights[i]})
        for (( j = $1; j < n; j++ ))
        do
            if [ $i -eq $j ]
            then
                continue
            fi
            if [ $(( $weight + ${weights[j]} )) -gt $backpackVolume ]
            then
                continue
            else
                weight=$(( $weight + ${weights[j]} ))
                amount=$(( $amount + ${values[j]} ))
                array+=(${weights[j]})
            fi
        done
        updateIfAmountGreater
    done
}

for (( i = 0; i < n; i++ ))
do
    fillBackpack i
done

echo "Amount = ${maxValue}"
echo "Items = ${result[*]}"
