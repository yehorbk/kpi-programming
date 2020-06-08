'use strict';

const pipe = (...fns) =>
  (fns.forEach(v => {
    if (typeof v !== 'function') throw new Error('Not a function');
  }), x => fns.reduce(((prev, cur) => cur(prev)), x));

module.exports = { pipe };
