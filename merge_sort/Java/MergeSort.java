package prog5;

import java.util.Random;
import java.util.Scanner;

public class MergeSort {
    void mergesort(int []arr,int l,int h){
        int mid = (l+h)/2;
        if(h>l){
            mergesort(arr,l,mid);
            mergesort(arr,mid+1,h);
            merge(arr,l,mid,h);
        }
    }
    private void merge(int []arr,int l,int m,int h){
        int []c = new int[1000];
        int i=l;
        int j=m+1;
        int k=l;
        while(i<=m && j<=h){
            if(arr[i]<arr[j])
                c[k]=arr[i++];
            else
                c[k]=arr[j++];
            k++;
        }
        while(i<=m)
            c[k++]=arr[i++];
        while(j<=h)
            c[k++]=arr[j++];
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
