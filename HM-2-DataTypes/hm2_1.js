'use strict'

const hoisting = () => {
    console.log(number);
    //let number = 3; // It cause Runtime Exception
    var number = 3;
    console.log(number);
}

hoisting();