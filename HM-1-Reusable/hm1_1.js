'use strict'

let name = 'Yehor';
const YEAR = 2002;

const greeting = name => {
    console.log(name);
}

greeting('Bob');
greeting(name);
greeting(YEAR);