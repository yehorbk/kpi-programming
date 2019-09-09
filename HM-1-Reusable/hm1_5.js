"use strict"

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