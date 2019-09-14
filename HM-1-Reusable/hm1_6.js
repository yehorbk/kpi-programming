'use strict';

const phonesHash2 = {
  Bob: '+380445554433',
  Alex: '+30743534453',
  Ann: '+380986423436'
};

const findPhoneByNameHash2 = name => phonesHash2[name];

console.log(findPhoneByNameHash2('Bob'));
