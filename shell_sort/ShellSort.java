import java.util.Arrays;

public class ShellSort {

    // Driver method for testing sort algorithm
    public static void main(String[] args) {
        int[] array = {21, 3, 82, 12, 93, 56, 74, 38};
        System.out.println("Before sort: " + Arrays.toString(array));
        shellSort(array);
        System.out.println("After sort: " + Arrays.toString(array));
    }

    /**
     *
     * Sorts an array by implementing the shell sort algorithm.
     * Shell sort is an in-place comparison sort
     * <p>
     * Average case = depends on the gap<br>
     * Worst case = O(n * log^2 n)<br>
     * Best case = O(n)<br>
     *
     * @param array an unsorted array
     */
    public static void shellSort(int[] array) {
        int inner, outer;
        int temp;

        int h = 1;
        while (h <= array.length / 3) {
            h = h * 3 + 1;
        }
        while (h > 0) {
            for (outer = h; outer < array.length; outer++) {
                temp = array[outer];
                inner = outer;

                while (inner > h - 1 && array[inner - h] >= temp) {
                    array[inner] = array[inner - h];
                    inner -= h;
                }
                array[inner] = temp;
            }
            h = (h - 1) / 3;
        }
    }
}

