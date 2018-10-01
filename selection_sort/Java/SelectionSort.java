import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Firstly Hit a number for a test case,");
        System.out.println(" followed by Size of array then the elements to be sorted"); 
        int test= scan.nextInt();
        for(int i=0; i<test; i++){
            int size= scan.nextInt();
            int []arr = new int[size];
            fillElements(size, arr);
            int []res= ssort(arr);
            printarr(res);
    }


    }

    public static int[] ssort(int[] arr) {
        int min_index = 0;
        for(int i=0; i<arr.length-1; i++){
            min_index = i;
            for(int j = i + 1 ; j < arr.length; j++){
                if(arr[j] < arr[min_index] ){
                    min_index = j;
                }
                swapp(min_index, i, arr);
               /* int temp = arr[min_index];
                arr[min_index] = arr[i];
                arr[i] = temp;*/
            }
        }
        return arr;
    }

     public static void swapp(int a, int b, int[] arr){
            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
     }
     
      public static void fillElements(int size, int[] arr) {
        Scanner scan = new Scanner(System.in);
        for(int i=0; i<size; i++){
            arr[i]= scan.nextInt();
        }
    }
       
      public static void printarr(int[] res) {
        for(int i = 0; i < res.length; i++){
            System.out.print(res[i] + " ");
        }
    }

}


