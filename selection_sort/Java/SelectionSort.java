public class SelectionSort{

     public static void main(String []args){
        int[] arr = new int[] {53,2,7,1,10,9};
        selectionSort(arr);
        System.out.println("Hello World");
        for (int i=0; i< arr.length; i++) {
            System.out.println(arr[i]);
        }
     }

     public static void selectionSort(int[] array) {
         for (int i = 0; i < array.length; i++) {
             int min_index = i;
             int temp = 0;
             for (int j=i; j < array.length; j++) {
                 if (array[min_index] > array[j]) {
                     min_index = j;
                 }
             }
             temp = array[i];
             array[i] = array[min_index];
             array[min_index] = temp;
         }
     }
}
