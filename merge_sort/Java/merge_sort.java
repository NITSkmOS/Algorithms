import java.util.Arrays;

class merge_sort {

    //Main function. Instanciates the unsorted array and calls mergesort.
    public static void main(String args[]) {

        int intArray[] = {9, 5, 4, 6, 1, 2, 3, 1, 2, 3};
        System.out.println("The unsorted array is:");
        System.out.println(Arrays.toString(intArray));

        mergesort(intArray);

        System.out.println("The sorted array is:");
        System.out.println(Arrays.toString(intArray));
    }

    //Splits array by half, creating two new arrays.
    //Calls mergesort recursively on both of them.
    //(they are expected to be returned sorted)
    //then unifies them on the initial array calling merge.
    static void mergesort(int intArray[]) {
        int size = intArray.length;
        if (size < 2) return;
        int mid = size / 2;
        int left[] = new int[mid];
        int right[] = new int[size - mid];
        for (int i = 0; i < mid; i++) left[i] = intArray[i];
        for (int i = mid; i < size; i++) right[i - mid] = intArray[i];
        mergesort(left);
        mergesort(right);
        merge(intArray, left, right);
    }

    //Unifies left and right on array.
    //Both of them are expected to be already sorted.
    //Goes through every index of left and right
    //comparing values and saves the lesser one on array.
    public static void merge(int array[], int left[], int right[]) {
        int sizeLeft = left.length;
        int sizeRight = right.length;
        int i = 0, j = 0, k = 0;
        while (i < sizeLeft && j < sizeRight) {
            if (left[i] <= right[j]) {
                array[k] = left[i];
                i++;
            } else {
                array[k] = right[i];
                j++;
            }
            k++;
        }
        while (i < sizeLeft) {
            array[k] = left[i];
            i++;
            k++;
        }
        while (j < sizeRight) {
            array[k] = right[j];
            j++;
            k++;
        }
    }
}
