class SelectionSort {

    /**
     * Selection sort works as, the local  minimum number to be put at index
     * The minimum number will go in 0 position, second minimum number in the array will go in the 1st position and so on.
     * <p>
     * *
     */

    public static void main(String[] args) {
        int arr[] = {3, 4, 9, 1, 2, 10}
        selectionSort(arr);

        printArr(arr);

    }

    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int index = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[index]) {
                    index = j;
                }
            }

            int localSmallerNumber = arr[index];
            arr[index] = arr[i];
            arr[i] = localSmallerNumber;
        }
    }

    public static void printArr(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + "\t");
        }
        System.out.println();
    }

}
