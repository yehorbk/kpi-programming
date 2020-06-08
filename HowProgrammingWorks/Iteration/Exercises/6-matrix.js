'use strict';

const max = matrix => {
  let max = -Infinity;
  for (let row = 0; row < matrix.length; row++) {
    for (let item = 0; item < matrix[row].length; item++) {
      if (matrix[row][item] > max) {
        max = matrix[row][item];
      }
    }
  }
  return max;
};

/* ANOTHER IMPLEMENTATION

const max = matrix => {
  const reducer = (acc, val) => (acc > val ? acc : val);
  const mapper = val => val.reduce(reducer);
  return matrix.map(mapper).reduce(reducer);
}

*/

module.exports = { max };
