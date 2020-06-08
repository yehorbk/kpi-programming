'use strict';

const ages = persons => {
  const result = {};
  for (const key in persons) {
    const value = persons[key];
    result[key] = value.died - value.born;
  }
  return result;
};

module.exports = { ages };
