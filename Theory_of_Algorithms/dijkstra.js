'use strict';

const SIZE = 4;

const matrix = [
    [0, 30, 19, 9],
    [30, 0, 15, 55],
    [19, 15, 0, 24],
    [9, 55, 24, 0],
];
const minimalRoute = [];

let visitedVertexes = [];
let temp, minIndex, min;
let beginIndex = 0;

for (let i = 0; i < SIZE; i++) {
    minimalRoute[i] = Infinity;
    visitedVertexes[i] = 1;
}
minimalRoute[beginIndex] = 0;

do {
    minIndex = Infinity;
    min = Infinity;
    for (let i = 0; i < SIZE; i++) {
        if ((visitedVertexes[i] === 1) && (minimalRoute[i] < min)) {
            min = minimalRoute[i];
            minIndex = i;
        }
    }
    if (minIndex !== Infinity) {
        for (let i = 0; i < SIZE; i++) {
            if (matrix[minIndex][i] > 0) {
                temp = min+ matrix[minIndex][i];
                if (temp < minimalRoute[i]) {
                    minimalRoute[i] = temp;
                }
            }
        }
        visitedVertexes[minIndex] = 0;
    }
} while(minIndex < Infinity);

console.log(minimalRoute);


visitedVertexes = [];
let endIndex = 2;
visitedVertexes[0] = endIndex + 1;
let previousIndex = 1;
let weight = minimalRoute[endIndex];

while(endIndex !== beginIndex) {
    for (let i = 0; i < SIZE; i++) {
        if (matrix[i][endIndex] !== 0) {
            let temp = weight - matrix[i][endIndex];
            if (temp === minimalRoute[i]) {
                weight = temp;
                endIndex = i;
                visitedVertexes[previousIndex] = i + 1;
                previousIndex++;
            }
        }
    }
}

console.log(visitedVertexes);
