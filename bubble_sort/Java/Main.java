/*
* Testing Class to test functionality of bubble sort
**/

import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        ArrayList<Integer> arr = new ArrayList<>();

        int amount;
        System.out.println("\nHow many numbers are there on which you want to apply bubble sort ?");
        amount = scanner.nextInt();

        int tempNo;
        System.out.println("\nEnter numbers on which you want to apply bubble sort");
        for (int i = amount - 1; i >= 0; i--)
        {
            tempNo = scanner.nextInt();
            arr.add(tempNo);
        }

        BubbleSort bubbleSort = new BubbleSort(arr);
        bubbleSort.printSortedList();
    }
}
