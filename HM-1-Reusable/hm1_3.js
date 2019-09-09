'use strict'

const average = (a, b) => {
    return (a + b) / 2;
}

const square = (x) => {
    return x * x;
}

const cube = (x) => {
    return x * x * x;
}

for (let i = 0; i < 10; i++) {
    console.log(average(square(i), cube(i)));
}