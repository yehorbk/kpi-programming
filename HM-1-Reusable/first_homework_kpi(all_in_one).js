"use strict"

// Identifiers //
console.log("\nIdentifiers:");

let name = "Yehor";
const YEAR = 2002;

const greeting = name_arg => {
    console.log(name_arg);
}

greeting(name);
greeting(YEAR);


// Loops //
console.log("\nLoops:");

const range = (start, end) => {
    for (let i = start; i <= end; i++) {
        if (i % 2 == 1) {
            console.log(i);
        }
    }
}

range(15, 30);


// Functions //
console.log("\nFunctions:");

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


// Objects //
console.log("\nObjects:");

const user1 = { name: "Alex" };
let user2 = { name: "Serj" };

console.log(user1.name);
console.log(user2.name);

user1.name = "Ann";
user2.name = "Max";

console.log(user1.name);
console.log(user2.name);

//user1 = { name: "Ann" }; // It cause an Runtime Exception, because const variable cannot be changed
user2 = { name: "Max" };

const createUser = (name, city) => {
    return { name: name, city: city };
}

let user3 = createUser("Bob", "San Francisco");

console.log(user3);


// Arrays //
console.log("\nArrays:");

let phonesArray = [
    { name: "Bob", phone: "+380445554433" },
    { name: "Alex", phone: "+30743534453" },
    { name: "Ann", phone: "+380986423436" },
];

const findPhoneByName = (name) => {
    let result = "No such user in the book!";
    for (let i = 0; i < phonesArray.length; i++) {
        if (name == phonesArray[i].name) {
            result = phonesArray[i].phone;
            break;
        }
    }
    return result;
}

console.log(findPhoneByName("Ann"));


// Hash Tables #1 //
console.log("\nHash Tables #1 (My version):");

let phonesHash1 = [];
phonesHash1["Bob"] = "+380445554433";
phonesHash1["Alex"] = "+30743534453";
phonesHash1["Ann"] = "+380986423436";

let findPhoneByNameHash = (name) => {
    return phonesHash1[name];
}

console.log(findPhoneByNameHash("Alex"));


// Hash Tables #2 //
console.log("\nHash Tables #2 (Teacher version):");

let phonesHash2 = {
    Bob: "+380445554433",
    Alex: "+30743534453",
    Ann: "+380986423436"
};

findPhoneByNameHash = (name) => {
    return phonesHash2[name];
}

console.log(findPhoneByNameHash("Bob"));