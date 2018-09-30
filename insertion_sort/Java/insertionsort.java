package java;
import java.util.*;
class InsertionSort 
{ 
    /*Function to sort array using insertion sort*/
    public static void insertionsort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=1; i<n; ++i) 
        { 
            int key = arr[i]; 
            int j = i-1; 
  
            /* Move elements of arr[0..i-1], that are 
               greater than key, to one position ahead 
               of their current position */
            while (j>=0 && arr[j] > key) 
            { 
                arr[j+1] = arr[j]; 
                j = j-1; 
            } 
            arr[j+1] = key; 
        } 
    } 
    // Driver method 
     public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of values :");
        int var = sc.nextInt();
        System.out.println("Enter the values :");
        int arr[] = new int[var];
        for(int i =0 ; i < var ;i++)
        arr[i] = sc.nextInt();
        InsertionSort ob = new InsertionSort();
        ob.insertionsort(arr);
        sc.close();
         int n = arr.length; 
          for (int i=0; i<n; ++i)
              System.out.print(arr[i] + " ");
          System.out.println();
    }
} 
