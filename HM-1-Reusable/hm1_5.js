'use strict'

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