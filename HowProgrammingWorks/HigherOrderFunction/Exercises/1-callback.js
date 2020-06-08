'use strict';

const iterate = (obj, callback) => {
  for(const item in obj) {
    const value = obj[item];
    callback(item, value, obj);
  }
};

module.exports = { iterate };
