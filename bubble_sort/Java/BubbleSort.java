/*
* I have converted the code of bubble sort written in C++ into Java with some little modifications,
* C++ code: https://github.com/NITSkmOS/Algorithms/blob/master/bubble_sort/Cpp/bubble_sort.cpp
* */

import java.util.ArrayList;
import java.util.Scanner;

public class BubbleSort
{
    private ArrayList<Integer> arr;

    public BubbleSort(ArrayList<Integer> arr)
    {
        this.arr = arr;
        bubbleSort();       // Main bubble sort algorithm is called
    }

    // Wrapper class is used so that values are changed inside the function
    private void swap(int j)
    {
        int temp = arr.get(j);
        arr.set(j, arr.get(j + 1));
        arr.set(j+1, temp);
    }

    private void bubbleSort()
    {
        int i, j;
        Boolean swapped;
        for (i = 0; i < arr.size(); i++)
        {
            swapped = false;
            for (j = 0; j < arr.size()-i-1; j++)
            {
                if (arr.get(j) > arr.get(j+1))
                {
                    swap(j);
                    swapped = true;
                }
            }

            // If no two elements were swapped by inner loop, then break
            if (!swapped)
                break;
        }
    }

    void printSortedList()
    {
        System.out.println("\nNumbers after applying bubble sort algorithm are: ");
        int i;
        for (i = 0; i < arr.size(); i++)
        {
            System.out.print(arr.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args)
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
