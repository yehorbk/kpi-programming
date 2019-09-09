'use strict'


// Example #1:
console.log("\nExample #1: ");

const inc = (n) => {
    return ++n;
}

const a = 5;
const b = inc(a);

console.dir({ a, b });


// Example #2:
console.log("\nExample #2: ");

const inc1 = (num) => {
    return ++num.n;
}

const obj = { n: 5 };
inc1(obj);
console.dir(obj);