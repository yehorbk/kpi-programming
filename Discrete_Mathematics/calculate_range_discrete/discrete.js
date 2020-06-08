'use strict';

const SEPARATOR = '--------------------------------------';

(() => {

    const limitA = { min: 1, max: 10 }; // Limits for the first range
    const limitB = { min: 5, max: 20 }; // Limits for the second range

    const A = getRange(limitA);
    const B = getRange(limitB);

    const condition = (a, b) => { 
        return Math.sin(a) == Math.sin(b); // Task condition for the result generation
    };

    const RRange = getResult(A, B, condition);
    const RMatrix = getMatrix(A, B, condition);

    printResult(RRange);
    console.log(SEPARATOR);
    printResult(RMatrix);

})();

function getRange(limit) {
    let range = [];
    for (let i = limit.min; i <= limit.max; i++) {
        range.push(i);
    }
    return range;
}

function getResult(A, B, condition) {
    let result = [];
    for (let i = 0; i < A.length; i++) {
        for (let j = 0; j < B.length; j++) {
            if (condition(A[i], B[j])) {
                result.push([A[i], B[j]]);
            }
        }
    }
    return result;
}

function getMatrix(A, B, condition) {
    let matrix = [];
    for (let i = 0; i < B.length; i++) {
        let row = [];
        for (let j = 0; j < A.length; j++) {
            row.push(Number(condition(A[j], B[i])));
        }
        matrix.push(row);
    }
    return matrix;
}

function printResult(result) {
    for (let i = 0; i < result.length; i++) {
        console.log(result[i]);
    }
}


//if the only one matrix is given, second becomes equal to first given
//in this way you can self-compose the matrix
function compose(matrixA, matrixB = matrixA) {
  //make another matrix to return
  const composedMatrix = [];
  //get the size of given matrix
  const matrixSize = matrixA.length
  if (matrixSize !== matrixB.length) return 1;
  //fill composedMatrix with zeros
  for (let i = 0; i < matrixSize; i++) {
    //empty row
    composedMatrix[i] = [];
    for (let j = 0; j < matrixSize; j++) {
      //row fills with zeros
      composedMatrix[i][j] = 0;
    }
  }
  //elements, that satisfy the composition requirements, are equal to 1
  for (let i = 0; i < matrixSize; i++) {
    for (let j = 0; j < matrixSize; j++) {
      for (let k = 0; k < matrixSize; k++) {
        if (composedMatrix[i][k] === 1) continue;
        if (matrixA[i][j] === matrixB[j][k] && 
            matrixA[i][j] === 1)
        composedMatrix[i][k] = 1;
      }
    }
  }
  return composedMatrix;
}

const isReflexive = matrix => {
  for (let i = 0; i < matrix.length; i++) {
    if (matrix[i][i] === 0) return false;
  }
  return true;
};

const isAntiReflexive = matrix => {
  for (let i = 0; i < matrix.length; i++) {
    if (matrix[i][i] !== 0) return false;
  }
  return true;
};

const isSymmetric = matrix => {
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      if (matrix[i][j] !== matrix[j][i]) return false;
    }
  }
  return true;
};

const isAntiSymmetric = matrix => {
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      if (matrix[i][j] + matrix[j][i] > 1 && 
          i !== j) 
      return false;
    }
  }
  return true;
};

const isTransitive = matrix => {
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix.length; j++) {
      for (let k = 0; k < matrix.length; k++) {
        if (matrix[i][j] + matrix[j][k] > 1 && 
            matrix[i][j] === 0)
        return false;
      }
    }
  }
  return true;
};

const isRelationOfOrder = (matrix, strictOrder) => {
  return isTransitive(matrix) &&
  isAntiSymmetric(matrix) &&
  ((strictOrder)? isAntiReflexive(matrix) : isReflexive(matrix));
};
/*

if (result[i] == 1) {
            console.log('\x1b[32m', result[i]);
        } else if (result[i] == 0) {
            console.log('\x1b[31m', result[i]);
        } else {
            console.log(result[i]);
        }

        */
