'use strict';

const methods = iface => {
  const result = [];
  for (const item in iface) {
    const fn = iface[item];
    if (typeof fn === 'function') {
      result.push([item, fn.length]);
    }
  }
  return result;
};

module.exports = { methods };
