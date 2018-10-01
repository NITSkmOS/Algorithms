import java.util.Scanner;

public class InsertionSort {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
            System.out.print("Firstly Hit a number for a test case,");
            System.out.println(" followed by Size of array then the elements to be sorted"); 
            int test = scan.nextInt();
            while (test > 0) {
            int size = scan.nextInt();
            int[] arr = new int[size];
            buildArray(arr);
            int[] m = insertionsort(arr);
            printarr(m);
            size--;
        }
    }

    private static int[] insertionsort(int[] arr) {
        int key = 0;
        int j = 0;
        for(int i = 1; i < arr.length; i++){
            key = arr[i];
            j = i - 1;
            while(j >= 0 && arr[j] > key){
                arr[j+1] = arr[j];
                j = j - 1;
            }
            arr[j+1] = key;
        }
        return arr;
    }

    private static void buildArray(int[] arr) {
        for(int i = 0; i < arr.length; i++)
            arr[i] = scan.nextInt();
    }
     public static void printarr(int[] res) {
        for(int i = 0; i < res.length; i++){
            System.out.print(res[i] + " ");
        }
    }
}
