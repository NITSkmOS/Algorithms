
public class BinarySearch {

	public int search(int[] arr, int size, int num) {
		int left = 0;
		int right = size - 1;
		while (left <= right) {
			int m = (left + right) / 2;
			if (arr[m] < num) {
				left = m + 1;
			} else if (arr[m] > num) {
				right = m - 1;
			} else {
				return m;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		BinarySearch bs = new BinarySearch();
		int[] arr = { 1,14,26,95,99 };
		int size = arr.length;
		int num = 14;
		System.out.println(bs.search(arr, size, num));
	}
}
