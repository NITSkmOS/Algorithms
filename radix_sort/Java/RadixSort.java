public class RadixSort {

    static void print(int[] nums) {
        for (int num : nums) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    static void radixSort(int[] nums) {
        int maxValue = -1;
        for (int i : nums) {
            maxValue = Math.max(maxValue, i);
        }
        int val = 1;
        int n = nums.length;
        while (maxValue / val > 0) {
            int[] helper = new int[10];
            for (int i : nums) {
                helper[(i/val)%10]++;
            }
            for (int i=1; i<10; i++) {
                helper[i] += helper[i-1];
            }
            int[] arr = new int[n];
            for (int i=n-1; i>=0; i--) {
                helper[(nums[i]/val)%10]--;
                arr[helper[(nums[i]/val)%10]] = nums[i];
            }
            for (int i=0; i<n; i++) {
                nums[i] = arr[i];
            }
            val *= 10;
        }
    }

    public static void main(String[] args) {
        int[] nums = {170, 45, 75, 90, 802, 2, 24, 66, 23, 234, 3, 232, 44};
        System.out.print("Before Sorting: ");
        print(nums);
        radixSort(nums);
        System.out.print("After Sorting: ");
        print(nums);
    }
}
