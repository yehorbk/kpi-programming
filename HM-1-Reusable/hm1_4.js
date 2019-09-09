'use strict'

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