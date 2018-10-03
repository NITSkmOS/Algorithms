import java.util.Arrays;

public class InsertionSort {

	public static void main(String[] args) {
		int[] array = { 6, 5, 4, 3, 2, 1 };
		sort(array, 0, array.length-1);
		System.out.println(Arrays.toString(array));
	}

	public static void sort(int[] array, int leftIndex, int rightIndex) {
		if (array != null && leftIndex < rightIndex && leftIndex >= 0 && rightIndex >= 0 && array.length > 0
				&& array.length >= rightIndex) {

			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				int k = i;
				while (k > 0 && array[k - 1] > (array[k])) {
					swap(array, k - 1, k);
					k--;
				}
			}
		}
	}

	public static void swap(int[] array, int i, int j) {
		if (array == null)
			throw new IllegalArgumentException();

		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
