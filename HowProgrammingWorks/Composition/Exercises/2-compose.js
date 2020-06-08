'use strict';

const compose = (...fns) => {
  let listener = null;
  const fn = x => fns.reverse().reduce((prev, cur, index, arr) => {
    try {
      return cur(prev);
    } catch (e) {
      listener(e);
      arr.splice(1);
      return undefined;
    }
  }, x);
  fn.on = (type, callback) => {
    if (type === 'error') listener = callback;
  };
  return fn;
};

module.exports = { compose };
