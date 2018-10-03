import java.util.Arrays;

public class MergeSort {

	public static void main(String[] args) {
		int[] array = { 6, 5, 4, 3, 2, 1 };
		sort(array, 0, array.length-1);
		System.out.println(Arrays.toString(array));
	}

	public static void sort(int[] array, int leftIndex, int rightIndex) {
		if (leftIndex < rightIndex) {
			int mid = (leftIndex + rightIndex) / 2;
			sort(array, leftIndex, mid);
			sort(array, mid + 1, rightIndex);
			merge(array, leftIndex, mid, rightIndex);
		}
	}

	private static void merge(int[] array, int leftIndex, int mid, int rightIndex) {
		int i = leftIndex;
		int j = mid + 1;
		int k = leftIndex;

		int[] aux = Arrays.copyOf(array, array.length);

		while (i <= mid && j <= rightIndex) {
			if (aux[i] < (aux[j])) {
				array[k] = aux[i];
				i++;
			} else {
				array[k] = aux[j];
				j++;
			}
			k++;
		}

		while (i <= mid) {
			array[k] = aux[i];
			i++;
			k++;
		}

		while (j <= rightIndex) {
			array[k] = aux[j];
			k++;
			j++;
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
