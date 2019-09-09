'use strict'

// Identifiers //
console.log('\nIdentifiers:');

let name = 'Yehor';
const YEAR = 2002;

const greeting = name_arg => {
    console.log(name_arg);
}

greeting(name);
greeting(YEAR);


// Loops //
console.log('\nLoops:');

const range = (start, end) => {
    for (let i = start; i <= end; i++) {
        if (i % 2 == 1) {
            console.log(i);
        }
    }
}

range(15, 30);


// Functions //
console.log('\nFunctions:');

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


// Objects //
console.log('\nObjects:');

const user1 = { name: 'Alex' };
let user2 = { name: 'Serj' };

console.log(user1.name);
console.log(user2.name);

user1.name = 'Ann';
user2.name = 'Max';

console.log(user1.name);
console.log(user2.name);

//user1 = { name: 'Ann' }; // It cause an Runtime Exception, because const variable cannot be changed
user2 = { name: 'Max' };

const createUser = (name, city) => {
    return { name, city };
}

let user3 = createUser('Bob', 'San Francisco');

console.log(user3);


// Arrays //
console.log('\nArrays:');

const phonesArray = [
    { name: 'Bob', phone: '+380445554433' },
    { name: 'Alex', phone: '+30743534453' },
    { name: 'Ann', phone: '+380986423436' },
];

const findPhoneByName = (name) => {
    return phonesArray.find((item) => {
        return item.name === name;
    }).phone;
}

console.log(findPhoneByName('Ann'));


// Hash Tables #2 //
console.log('\nHash Tables:');

const phonesHash = {
    Bob: '+380445554433',
    Alex: '+30743534453',
    Ann: '+380986423436'
};

const findPhoneByNameHash = (name) => {
    return phonesHash[name];
}

console.log(findPhoneByNameHash('Bob'));