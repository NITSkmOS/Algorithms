public class selection_sort {

    //Main function. Instanciates the unsorted array and calls mergesort.
    public static void main(String args[]) {

        //Example Array
        int example[] = {9, 5, 4, 6, 1, 2, 3, 1, 2, 3};
        selection_sort(example);
        print_sorted_array(example);
    }

    //    Method to take minimum and switch it with each successive place in the array through the penultimate index
    static void selection_sort(int array[]) {
        int len = array.length;
        for (int i = 0; i < len - 1; i++) {
            int min = i;
//            Checks for minimum through entire array
            for (int j = i + 1; j < len; ++j) {
                if (array[j] < array[min])
                    min = j;
            }
//            temp is needed in order to be able to switch the two values.
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }

    //Method taken from bubble_sort.java
    //Method to print an array
    public static void print_sorted_array(int arr[]) {

        //storing the length of an array using the .length function in Java
        int n = arr.length;
        //For loop that iterates over each element of the array and then prints it.
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
