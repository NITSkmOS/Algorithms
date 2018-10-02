import java.util.Scanner;

public class InsertionSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.println("Enter size: ");
		int n = s.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter elements: ");
		for (int i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}
		insertionsort(arr);

	}

	public static void insertionsort(int arr[]) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = i; j > 0; j--) {
				if (arr[j] < arr[j - 1]) {
					int temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
				}
			}
		}
		for (int i = 0; i < arr.length; i++) {
			System.out.println(arr[i]);
		}
	}
}
