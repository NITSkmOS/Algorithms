import java.util.Arrays;

/*
    Binary search implemenetation that looks up index of a number in a collection.
    If the number doesn't exist return -1.
 */
public class BinarySearch {

    public static void main(String[] args) {
        // write your code here
        int[] nums = { 3, 4, 1, 2, 5 };
        int key = 5;
        Arrays.sort(nums);
        System.out.println(findIndex(nums, key) + 1);
    }

    private static int findIndex(int[] nums, int key) {
        int index = -1;
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == key)
                return mid;
            else if (nums[mid] > key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return index;
    }
}
