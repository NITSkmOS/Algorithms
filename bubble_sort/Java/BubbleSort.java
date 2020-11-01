public class BubbleSort {
    public static void main(String[] args) {
        //Taking a sample array for sorting it.
        int[] nums = {12, 45, 23, 78, 67};

        //calling the method and passing the array in it.
        bubbleSort(nums, nums.length);
        //Printing the sorted array
        printSortedArray(nums);
    }

    //The recurisve method that takes in the array and the length of it.
    public static void bubbleSort(int[] nums, int end) {
        //base case
        if (end == 1) {
            return;
        }
        //for loop that iterates and sorts the sorts the array
        for (int i = 0; i < end - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        }
        //calling the method again to sort the rest of the elements on next iteration
        bubbleSort(nums, end - 1);
    }

    //Method to print an array
    public static void printSortedArray(int arr[]) {

        //storing the length of an array using the .length function in Java
        int n = arr.length;
        //For loop that iterates over each element of the array and then prints it.
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

}
