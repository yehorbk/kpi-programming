'use strict';

/*    Nearest Neighbor Algorithm    */

const greedy = (matrix) => {
    const visitedVertexes = [];
    const result = {
        route: [],
        length: 0,
    };
    let i = 0;
    do {
        visitedVertexes.push(i);
        const minRoute = {
            index: Infinity,
            value: Infinity,
        }
        for (let j = 0; j < matrix.length; j++) {
            if (visitedVertexes.includes(j)) {
                continue;
            }
            if (matrix[i][j] < minRoute.value) {
                minRoute.index = j;
                minRoute.value = matrix[i][j];
            }
        }
        result.route.push([i, minRoute.index]);
        result.length += minRoute.value;
        i = minRoute.index;
    } while (visitedVertexes.length < matrix.length - 1);
    return result;
}

const matrix1 = [
    [0, 30, 19, 9],
    [30, 0, 15, 55],
    [19, 15, 0, 24],
    [9, 55, 24, 0],
];

const matrix2 = [
    [0, 80, 2],
    [80, 0, 10],
    [2, 10, 0],
];

const matrix3 = [
    [0, 30, 19, 9, 10, 33],
    [30, 0, 15, 55, 3, 20],
    [19, 15, 0, 24, 8, 102],
    [9, 55, 24, 0, 11, 46],
    [10, 3, 8, 11, 0, 25],
    [33, 20, 102, 46, 25, 0]
];

console.log(greedy(matrix1));
console.log(greedy(matrix2));
console.log(greedy(matrix3));
