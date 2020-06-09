import Cocoa

let matrix = [
    [1, 2, 3, 4, 5],
    [4, 3, 1, 5, 2],
    [3, 5, 2, 1, 4],
];

let x = 0;

func makeTransposition(matrix: [[Int]], x: Int) -> [[Int]] {
    var result: [[Int]] = matrix;
    for (i, array) in matrix.enumerated() {
        for j in 0..<array.count {
            result[i][j] = array.firstIndex(of: matrix[x][j])! + 1;
        }
    }
    return result;
}

func findInversions(matrix: [[Int]]) -> [[Int]] {
    var result: [[Int]] = [];
    for (i, array) in matrix.enumerated() {
        var counter: Int = 0;
        for j in 0..<array.count where j < (array.count - 1) {
            var k = j;
            while k < array.count {
                if (matrix[i][j] > matrix[i][k]) {
                    counter += 1;
                }
                k += 1;
            }
        }
        result.append([i, counter]);
    }
    return result;
}

func insertionSort(matrix: [[Int]]) -> [[Int]] {
    var result: [[Int]] = matrix;
        for i in 1..<result.count {
            let currentValue = result[i];
            var j = i;
            while j > 0 && currentValue[1] < result[j - 1][1] {
                result[j] = result[j - 1];
                j -= 1;
            }
            result[j] = currentValue;
        }
    return result;
}

let inversions = findInversions(matrix: makeTransposition(matrix: matrix, x: x));
let sorted = insertionSort(matrix: inversions);
print(sorted);
