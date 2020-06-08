'use strict';

const sum = (...args) => {
  let amount = 0;
  let i = 0;
  while (i < args.length) {
    amount += args[i++];
  }
  return amount;
};

module.exports = { sum };
