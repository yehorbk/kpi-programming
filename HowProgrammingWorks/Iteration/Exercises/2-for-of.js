'use strict';

const sum = (...args) => {
  let amount = 0;
  for (const item of args) {
    amount += item;
  }
  return amount;
};

module.exports = { sum };
