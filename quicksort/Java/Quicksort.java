import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Quicksort {
    static void quicksortArray(int[] array, int low, int high) {
        int i = low;
        int j = high;

        // The pivot is the middle index number
        int pivot = array[low + (high - low) / 2];

        while (i <= j) {
            while (array[i] < pivot) {
                i++;
            }

            while (array[j] > pivot) {
                j--;
            }

            if (i <= j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                i++;
                j--;
            }
        }

        if (low < j) {
            quicksortArray(array, low, j);
        }

        if (i < high) {
            quicksortArray(array, i, high);
        }
    }

    private static List<Integer> quicksortList(List<Integer> list) {

        if (list.size() <= 1) {
            return list;
        }

        List<Integer> less = new ArrayList<>();
        List<Integer> more = new ArrayList<>();
        List<Integer> equal = new ArrayList<>();

        int pivot = list.get(0);

        for (int i : list) {
            if (i < pivot) {
                less.add(i);
            } else if (i > pivot) {
                more.add(i);
            } else {
                equal.add(i);
            }
        }

        less = quicksortList(less);
        more = quicksortList(more);

        List<Integer> result = new ArrayList<>();
        result.addAll(less);
        result.addAll(equal);
        result.addAll(more);

        return result;

    }

    public static void main(String[] args) {
        int[] array = {1, 5, 4, 6, 2, 3};
        Quicksort.quicksortArray(array, 0, array.length - 1);

        System.out.println("Sorted array: " + Arrays.toString(array));

        List<Integer> list = new ArrayList<>(Arrays.asList(1, 5, 4, 6, 2, 3));
        List<Integer> sortedList = quicksortList(list);

        System.out.println("Sorted list: " + sortedList);
    }
}
