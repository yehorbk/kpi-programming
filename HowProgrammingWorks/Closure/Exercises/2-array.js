'use strict';

const array = () => {
  const data = [];
  function Arr(i) {
    return data[i];
  }
  Arr.push = function (item) {
    data.push(item);
  };
  Arr.pop = function () {
    return data.pop();
  };
  return Arr;
};

module.exports = { array };
