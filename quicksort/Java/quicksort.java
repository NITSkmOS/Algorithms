import java.util.Arrays;

class quicksort {
    //Main function. Instanciates the unsorted array and calls quicksort.
    public static void main(String args[]) {
        int array[] = {9, 5, 4, 6, 1, 2, 3, 1, 2, 3};
        System.out.println("The unsorted array is:");
        System.out.println(Arrays.toString(array));

        quicksort(array, 0, array.length - 1);

        System.out.println("The sorted array is:");
        System.out.println(Arrays.toString(array));
    }

    //partition returns the array splitted on
    // lesser and greater values than a pivot chosen randomly.
    //(on this case, the array's first value)
    //Then, quicksort is called recursively on both splits.
    static void quicksort(int array[], int start, int end) {
        if (start < end) {
            int pIndex = partition(array, start, end);
            quicksort(array, start, pIndex - 1);
            quicksort(array, pIndex + 1, end);
        }
    }

    //Defines the pivot index at the start of array.
    //Finds every element with lesser value and swaps places.
    //At the end of the cycle:
    // pivot splits the array on lesser and greater values.
    static int partition(int array[], int start, int end) {
        int pivot = array[end];
        int pIndex = start;
        for (int i = start; i < end; i++) {
            if (array[i] <= pivot) {
                swap(array, i, pIndex);
                pIndex++;
            }
        }
        swap(array, pIndex, end);
        return pIndex;
    }

    //Swaps indexes 'a' and 'b' on array
    static void swap(int array[], int a, int b) {
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }
}
