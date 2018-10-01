import java.util.Scanner;

public class BubbleSort {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Firstly Hit a number for a test case,");
        System.out.println(" followed by Size of array then the elements to be sorted");
        int test= scan.nextInt();
        for(int i=0; i<test; i++){
            int size= scan.nextInt();
            int []arr = new int[size];
            fillElements(size, arr);
            int []res= bsort(arr);
            printarr(res);
        }
    }

    public static void printarr(int[] res) {
        for(int i = 0; i < res.length; i++){
            System.out.print(res[i] + " ");
        }
    }

    public static int[] bsort(int[] arr) {
        int temp=0;
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr.length-i-1; j++){
                if(arr[j] > arr[j+1] ){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
               return arr;

    }


    public static void fillElements(int size, int[] arr) {
        Scanner scan = new Scanner(System.in);
        for(int i=0; i<size; i++){
            arr[i]= scan.nextInt();
        }
    }
}
