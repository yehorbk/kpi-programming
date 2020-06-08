'use strict';

const contract = (fn, ...types) => (...args) => {
  for (let i = 0; i < args.length; i++) {
    const currentType = typeof types[i]();
    if (typeof args[i] !== currentType) {
      throw new Error('TypeError');
    }
  }
  const result = fn(...args);
  if (typeof result !== typeof(types[types.length - 1]())) {
    throw new Error('TypeError');
  }
  return result;
};

module.exports = { contract };

// It works with args[i].constructor !== types[i] in some cases
