'use strict';

const phonesArray = [
  { name: 'Bob', phone: '+380445554433' },
  { name: 'Alex', phone: '+30743534453' },
  { name: 'Ann', phone: '+380986423436' },
];

const findPhoneByName = name => {
  const result = phonesArray.find(item => item.name === name);
  return result.phone;
};

console.log(findPhoneByName('Ann'));
