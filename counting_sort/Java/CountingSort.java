/*Counting Sort algorithm- In Counting sort, the frequencies of distinct elements of the array 
to be sorted is counted and stored in an auxiliary array, by mapping its value as an index of
the auxiliary array.
Time Complexity- The below algorithm takes time O(n+m)
where n= number of elements in the array to be sorted, and
m= size of the auxilliary array

This is a linear time algorithm and can be used when a small nember of elements needs to be sorted.
*/
public class CountingSort {
    static int[] countingSort(int[] array){
        //find the maximum element from the array
        int max = array[0];
        for (int i = 1; i < array.length;i++){
            if(array[i]>max){
                max= array[i];
            }
        }
        //declare an auxillary array
        int[] auxArray= new int[max+1];
        for(int i=0;i<array.length;i++){
            auxArray[array[i]]++;
        }
        //declare an sorted array of the same length
        int[] sortedAux= new int[array.length];
        int temp=0;
        int j=0;
        for(int i=0;i<max+1;i++){
            temp= auxArray[i];
            while(temp>0){
                sortedAux[j]=i;
                j++;
                temp--;
            }
        }
        return sortedAux;
    }
    public static void main(String[] args) {
        int[] array = {5,2,9,5,2,3,5};
        int[] sortedAux= countingSort(array);
        //printing the sorted array
        for(int i=0;i<sortedAux.length;i++){
            System.out.print(sortedAux[i]+" ");
        }
    }

}
