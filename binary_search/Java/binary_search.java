import java.util.*;


class binary_search {
    static int binarySearch(int arr[], int left, int right, int element) {
        if (right >= left) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == element)
                return mid;
            if (arr[mid] > element)
                return binarySearch(arr, left, mid - 1, element);
            return binarySearch(arr, mid + 1, right, element);
        }
        return -1;
    }

    public static void main(String args[]){
        int n = 10;       // defines the length of array
        int arr[] = {1,2,3,4,5,6,7,8,9,10};
        int element = 5;  // element to search its index
        int result = binarySearch(arr, 0, n - 1, element);
        if (result == -1)
            System.out.println("Element not present in the given array");
        else
            System.out.println("Element found at index " + result);

    }
}

