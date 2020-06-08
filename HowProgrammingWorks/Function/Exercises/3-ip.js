'use strict';

const ipToInt = (ip = '127.0.0.1') => ip.split('.')
  .map(item => parseInt(item))
  .reduce((acc, val, i, arr) => acc + (val << (8 * (arr.length - i - 1))), 0);

module.exports = { ipToInt };
