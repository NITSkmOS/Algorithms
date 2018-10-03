import java.util.Arrays;

public class QuickSort {

	public static void main(String[] args) {
		int[] array = { 6, 5, 4, 3, 2, 1 };
		sort(array, 0, array.length-1);
		System.out.println(Arrays.toString(array));
	}

	public static void sort(int[] array, int leftIndex, int rightIndex) {

		if (array.length > 1 && leftIndex < rightIndex) {
			int pivot = partition(array, leftIndex, rightIndex);
			sort(array, leftIndex, pivot - 1);
			sort(array, pivot + 1, rightIndex);
		}
	}

	private static int partition(int[] array, int leftIndex, int rightIndex) {
		int i = leftIndex;

		for (int j = leftIndex + 1; j <= rightIndex; j++) {
			if (array[j]< array[leftIndex]) {
				i++;
				swap(array, i, j);
			}
		}
		swap(array, leftIndex, i);
		return i;
	}

	public static void swap(int[] array, int i, int j) {
		if (array == null)
			throw new IllegalArgumentException();

		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
