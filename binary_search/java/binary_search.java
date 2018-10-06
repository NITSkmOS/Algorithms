import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.*;
public class c2 {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        StringBuilder st = new StringBuilder();
        int n = in.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)    //Taking array input of length n
            a[i]=in.nextInt();

        Arrays.sort(a);
        int num=in.nextInt(); //the number to be searched in the array
        int lb =0;
        int ub=n-1;
        int mid = (lb+ub)/2;
        int index = -1;
        while(lb<=ub){
            if(a[mid]==num){
                index = mid;
                break;
            }
            else if (a[mid]>num){
                ub = mid-1;
            }
            else
                lb = mid + 1;
        }
        if (index>=0)System.out.println("The number is found!");
        else System.out.println("The number is not found");
    }
}

//The Algo in details : https://en.wikipedia.org/wiki/Binary_search_algorithm
