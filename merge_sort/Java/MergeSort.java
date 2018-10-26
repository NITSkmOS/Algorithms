import java.util.Random;
import java.util.Scanner;

//Sorts an array, of given size, of randomly generated numbers using MergeSort Algorithm

public class MergeSort {

    //Recursively call mergesort, reducing the array size in every call
    void mergesort(int []arr,int l,int h){
        int mid = (l+h)/2;		//Split array into two virtual parts
        if(h>l){			//If array contains more than two elements
            mergesort(arr,l,mid);	//Sort first part recursively
            mergesort(arr,mid+1,h);	//Sort second part recursively
            merge(arr,l,mid,h);		//Merge sorted arrays into single sorted array
        }
    }

    //Merge two sorted arrays into a single sorted array
    private void merge(int []arr,int l,int m,int h){
        int []c = new int[l+h];		//create temporary array. This will hold the sorted array		

	//Copies of l,m,h. These will be modified, while originals remain unchanged.
        int i=l;			
        int j=m+1;
        int k=l;

	//Until we reach the end of either sub-array
        while(i<=m && j<=h){
	    //Fill the smaller element in the temporary array. Increment the counter of the array with the smaller value.
            if(arr[i]<arr[j])
                c[k]=arr[i++];
            else
                c[k]=arr[j++];
            k++;
        }

	//Fill the remaining part of the longer array (if existing) into the final array
        while(i<=m)
            c[k++]=arr[i++];
        while(j<=h)
            c[k++]=arr[j++];

	//Copy temporary array to the original array
        for(int x=l;x<=h;x++)
            arr[x]=c[x];
    }

    public static void main(String []args){
        MergeSort ms = new MergeSort();
        Scanner in = new Scanner(System.in);
        System.out.print("\nEnter number of elements: ");
        int num = in.nextInt();
        int []arr = new int[num];
        Random rand = new Random();
        for(int i=0;i<num;i++) {
            arr[i] = rand.nextInt(100);
            System.out.print(" " + arr[i]);
        }
        System.out.print("\n");
        ms.mergesort(arr,0,num-1);
        for(int i=0;i<num;i++)
            System.out.print(arr[i]+" ");
    }
}
