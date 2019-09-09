"use strict"

const average = (a, b) => {
    return (a + b) / 2;
}

const squere = (x) => {
    return x * x;
}

const cube = (x) => {
    return x * x * x;
}

for (let i = 0; i < 10; i++) {
    console.log(average(squere(i), cube(i)));
}