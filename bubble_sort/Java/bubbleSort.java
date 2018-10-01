//Program to bubble sort. This program is sorting recursively.

public class bubbleSort {
    public static void main(String[] args) {
	//You can also take input to osrt this element.
        int[] nums = {12, 45, 23, 78, 67};
	bubble(nums, nums.length);
	printSortedArray(arr);
    }

    public static void bubble(int[] nums, int end){

        if (end == 1){
            return;
        }

        for (int i = 0; i < end - 1; i++) {
            if (nums[i] > nums[i+1]){
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
            }
        }

        bubble(nums, end - 1);
    }

    public static void printSortedArray(int arr[]) { 
	int n = arr.length; 
	for (int i=0; i<n; ++i) 
	    System.out.print(arr[i] + " "); 
	System.out.println(); 
    } 

}
