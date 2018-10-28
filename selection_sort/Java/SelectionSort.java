import java.util.Random;

/*
 ____       _           _   _             ____             _   
/ ___|  ___| | ___  ___| |_(_) ___  _ __ / ___|  ___  _ __| |_ 
\___ \ / _ | |/ _ \/ __| __| |/ _ \| '_ \\___ \ / _ \| '__| __|
 ___) |  __| |  __| (__| |_| | (_) | | |  ___) | (_) | |  | |_ 
|____/ \___|_|\___|\___|\__|_|\___/|_| |_|____/ \___/|_|   \__|

*/

public class SelectionSort {

    public static void main(String[] args) {
        int[] unsortedArray = createRandomArray(40);
        int[] sortedArray = sort(unsortedArray);
        printArray(sortedArray);
    }

    private static int[] sort(int[] a) {
        int maxIdx = a.length - 1;
        for (int idx = 0; idx < maxIdx; idx++) {
            int minIdx = idx;
            for (int i = idx + 1; i <= maxIdx; i++) {
                if (a[i] < a[minIdx])
                    minIdx = i;
            }

            //swap
            int tmp = a[idx];
            a[idx] = a[minIdx];
            a[minIdx] = tmp;
        }
        return a;
    }

    private static int[] createRandomArray(int length) {
        int[] array = new int[length];
        Random rand = new Random();
        for (int i = 0; i < array.length; i++)
            array[i] = rand.nextInt(1000);
        return array;
    }

    private static void printArray(int[] array) {
        System.out.printf("[ ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]);
            if (i < array.length - 1)
                System.out.print(", ");
        }
        System.out.printf(" ]");
    }
}
