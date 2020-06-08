'use strict';

const sum = (...args) => {
  let amount = 0;
  for (let i = 0; i < args.length; i++) {
    amount += args[i];
  }
  return amount;
};

module.exports = { sum };
