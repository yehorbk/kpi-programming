"use strict"

// Hash Tables #1 //
console.log("\nHash Tables #1 (My version):");

let phonesHash1 = [];
phonesHash1["Bob"] = "+380445554433";
phonesHash1["Alex"] = "+30743534453";
phonesHash1["Ann"] = "+380986423436";

const findPhoneByNameHash1 = (name) => {
    return phonesHash1[name];
}

console.log(findPhoneByNameHash1("Alex"));


// Hash Tables #2 //
console.log("\nHash Tables #2 (Teacher version):");

let phonesHash2 = {
    Bob: "+380445554433",
    Alex: "+30743534453",
    Ann: "+380986423436"
};

const findPhoneByNameHash2 = (name) => {
    return phonesHash2[name];
}

console.log(findPhoneByNameHash2("Bob"));