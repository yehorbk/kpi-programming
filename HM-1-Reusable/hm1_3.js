'use strict';

const average = (a, b) => (a + b) / 2;

const square = x => x * x;

const cube = x =>  x * x * x;

for (let i = 0; i < 10; i++) {
  console.log(average(square(i), cube(i)));
}
