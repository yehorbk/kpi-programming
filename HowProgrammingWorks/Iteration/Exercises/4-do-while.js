'use strict';

const sum = (...args) => {
  let amount = 0;
  let i = 0;
  if (args.length > 0) {
    do {
      amount += args[i++];
    } while (i < args.length);
  }
  return amount;
};

module.exports = { sum };
