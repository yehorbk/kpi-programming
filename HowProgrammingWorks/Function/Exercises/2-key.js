'use strict';

const generateKey = (length, possible) => {
  let result = '';
  const rand = max => Math.floor(Math.random() * max);
  for (let i = 0; i < length; i++) {
    result += possible[rand(possible.length)];
  }
  return result;
};

module.exports = { generateKey };
