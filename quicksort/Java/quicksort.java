import java.util.Scanner;

class QuickSortClass {
    public static void sort(int[] arr)
    {
        quickSort(arr, 0, arr.length - 1);
    }

    public static void quickSort(int arr[], int low, int high) 
    {
        int i = low, j = high;
        int temp;
        int pivot = arr[(low + high) / 2];

        while (i <= j) 
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
 
                i++;
                j--;
            }
        }
 
        if (low < j)
            quickSort(arr, low, j);
        if (i < high)
            quickSort(arr, i, high);
    }

    public static void main(String[] args) 
    {
      		int[] input = {89,56,2,48,23,41,69,10};
          System.out.println("Before Sorting : ");
          for (int j = 0; j < input.length; j++) {
            System.out.println(input[j]);}
          sort(input);
          System.out.println("==================");
          System.out.println("After Sorting : ");
          for (int i = 0; i < input.length; i++) {
            System.out.println(input[i]);
            } 
    }    
}