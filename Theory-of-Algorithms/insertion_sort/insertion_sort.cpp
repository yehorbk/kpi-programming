#include <iostream>
using namespace std;

bool isEven(int number) {
    return number % 2 == 0;
}

void printArray(int *array) {
    int length = 10;
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertSort(int *array) {
    int length = 10;
    for (int i = 1; i < length; i++) {
        int currentValue = array[i];
        int j = i;
        while (isEven(currentValue) && j > 0 && (array[j - 1] > currentValue || !isEven(array[j - 1]))) {
            if (isEven(array[j - 1]) && array[j - 1] < currentValue) {
                cout << array[j -1] << endl;
                break;
            } else {
                array[j] = array[j - 1];
                j -= 1;
            }
        }
        while (!isEven(currentValue) && j > 0 && (array[j - 1] < currentValue && !isEven(array[j - 1]))) {
            if (!isEven(array[j - 1]) && array[j - 1] > currentValue) {
                cout << array[j -1] << endl;
                break;
            } else {
                array[j] = array[j - 1];
                j -= 1;
            }
        }
        array[j] = currentValue;
    }
}

int main() {
    int array[] = { 30, 19, 9, 15, 55, 24, 3, 78, 46, 41 };
    insertSort(array);
    printArray(array);
    return 0;
}
