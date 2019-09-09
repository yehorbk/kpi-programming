'use strict'

const array = [true, 'hello', 5, -Infinity, undefined, 12, 'world', -200, false, 20, Infinity, false, 'word', 3.14, 244, -1, true, 'f', 0, {}, 32, { name: 'Bob' }, 'my string'];


// Example #1 //
console.log('\nExample #1: ');

const hash = {
    object: 0,
    number: 0,
    string: 0,
    boolean: 0,
    undefined: 0
};

for (let item of array) {
    hash[typeof item]++;
}

console.log(hash);


// Example #2 //
console.log('\nExample #2: ');

const hash1 = {};

for (let item of array) {
    hash1[typeof item] = isNaN(hash1[typeof item]) ? 1 : hash1[typeof item] + 1;
}

console.log(hash1);