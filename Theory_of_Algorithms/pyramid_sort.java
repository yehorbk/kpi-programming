class Program {

    private static void pyramidSort(int[] array) {
        int n = array.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(array, n, i);
        }
        for (int i = n - 1; i >= 0; i--) {
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;
            heapify(array, i, 0);
        }
    }

    private static void heapify(int[] array, int n, int i){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && array[l] > array[largest]) {
            largest = l;
        }
        if (r < n && array[r] > array[largest]) {
            largest = r;
        }
        if (largest != i) {
            int swap = array[i];
            array[i] = array[largest];
            array[largest] = swap;
            heapify(array, n, largest);
        }
    }

    private static void findMedian(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i % 2 == 0) {
                System.out.println("0 - " + i + ": " + array[i / 2]);
            } else {
                System.out.println("0 - " + i + ": " + array[i / 2] + ", " + array[i / 2 + 1]);
            }
        }
    }

    public static void main(String ...args) {
        int[] array = { 30, 19, 9, 15, 55, 24, 3, 78, 46, 41 };
        pyramidSort(array);
        findMedian(array);
    }

}
