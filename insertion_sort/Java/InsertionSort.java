class InsertionSort {
    /**
     * Insertion sort proceduce. Sorts the array in increasing
     * order in place. Time - O(n2), space O(1)
     * @param arr the array to be sorted.
     */
    static int[] insertionSort(int[] arr) {
        int i = 1;
        while (i < arr.length) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j -= 1;
            }
            arr[j + 1] = key;
            i += 1;
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = {
            5,
            1,
            7,
            11,
            4,
            1
        };
        int[] sorted_arr = insertionSort(arr);
        for (int each_num: sorted_arr) {
            System.out.print(each_num + " ");
        }
    }
}
