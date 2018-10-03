import java.util.Arrays;

public class BubbleSort {

	public static void main(String[] args) {
		int[] array = { 6, 5, 4, 3, 2, 1 };
		sort(array, 0, array.length-1);
		System.out.println(Arrays.toString(array));
	}

	public static void sort(int[] array, int leftIndex, int rightIndex) {
		if (array != null && leftIndex < rightIndex && leftIndex >= 0 && rightIndex >= 0 && array.length > 0
				&& array.length >= rightIndex) {

			int i = leftIndex;
			while (i < rightIndex) {
				boolean temTroca = false;
				for (int y = leftIndex; y < rightIndex - i; y++) {
					if (array[y] > array[y + 1]) {
						swap(array, y, y + 1);
						temTroca = true;
					}
				}
				if (!temTroca) {
					break;
				}
				i++;
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
