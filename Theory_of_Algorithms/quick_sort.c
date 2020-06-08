#include <stdio.h>

void swap(int *array, int i, int j, int *counter) {
    int buffer = array[i];
    array[i] = array[j];
    array[j] = buffer;
    (*counter)++;
}

void insertion(int *array, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int x = array[i];
        int j = i;
        while (j > left && array[j - 1] > x) {
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = x;
    }
}

int partition(int *array, int left, int right, int *counter) {
    int v = array[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array[i] < v) {
            i++;
        }
        while (array[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(array, i++, j--, counter);
    }
    return j;
}

int median(int a, int b, int c) {
    if (((a < b) && (b < c)) || ((c < b) && (b < a))) {
        return b;
    }
    if (((b < a) && (a < c)) || ((c < a) && (a < b))) {
        return a;
    }
    if (((a < c) && (c < b)) || ((b < c) && (c < a))) {
        return c;
    }
    return -1;
}

void qsort_standart(int *array, int left, int right, int *counter) {
    if (left < right) {
        int q = partition(array, left, right, counter);
        qsort_standart(array, left, q, counter);
        qsort_standart(array, q + 1, right, counter);
    }
}

void qsort_partition(int *array, int left, int right, int *counter) {
    int v = array[right];
    if (right <= left) {
        return;
    }
    int i = left;
    int j = right - 1;
    int p = left - 1;
    int q = right;
    while (i <= j) {
        while (array[i] < v) {
            i++;
        } 
        while (array[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(array, i, j, counter);
        if (array[i] == v) {
            p++;
            swap(array, p, i, counter);
        }
        i++;
        if (array[j] == v) {
            q--;
            swap(array, q, j, counter);
        }
        j--;
    }
    swap(array, i, right, counter);
    j = i - 1;
    i++;
    for (int k = left; k <= p; k++, j--) {
        swap(array, k, j, counter);
    }
    for (int k = right - 1; k >= q; k--, i++) {
        swap(array, k, i, counter);
    }
    qsort_partition(array, left, j, counter);
    qsort_partition(array, i, right, counter);
}

void qsort_faster(int *array, int left, int right, int *counter) {
    int M = 10;
    if (right - left <= M) {
        insertion(array, left, right);
        return ;
    }
    int med = median(array[left], array[(left + right) / 2], array[right]);
    swap(array, array[med], array[(left + right) / 2], counter);
    int i = partition(array, left, right, counter);
    qsort_faster(array, left, i, counter);
    qsort_faster(array, i + 1, right, counter);
}

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]); 
    }
    printf("\n");
}

int execute(void (*quicksort)(int *, int, int, int *), int *array, int length) {
    int counter = 0;
    int left = 0;
    int right = length - 1; 
    quicksort(array, left, right, &counter);
    return counter;
}

int main() {
    int length = 10;

    int array1[] = { 30, 19, 9, 15, 55, 24, 3, 78, 46, 41 };
    int array2[] = { 30, 19, 9, 15, 55, 24, 3, 78, 46, 41 };
    int array3[] = { 30, 19, 9, 15, 55, 24, 3, 78, 46, 41 };

    printf("Count: %d \n", execute(qsort_standart, array1, length));
    printArray(array1, length);

    printf("Count: %d \n", execute(qsort_faster, array2, length));
    printArray(array2, length);

    printf("Count: %d \n", execute(qsort_standart, array3, length));
    printArray(array3, length);

    return 0;
}
