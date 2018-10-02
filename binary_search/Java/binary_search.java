import java.util.Scanner;
import java.util.Arrays;

class BinarySearch {

	public static boolean binary_search(int ar[], int n, int target) {
		int lo = 0, hi = n-1;
		while(lo <= hi) {
			int mid = (lo + hi) / 2;
			if(ar[mid] == target) return true;
			if(ar[mid] < target) lo = mid + 1;
			else hi = mid - 1;
		}
	return false;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n, target;
		n = sc.nextInt();
		System.out.println("Enter no. of elements: ");
		int ar[] = new int[n];
		for(int i=0;i<n;++i) {
			ar[i] = sc.nextInt();
		}
		Arrays.sort(ar);
		System.out.println("Enter element for search: ");
		target = sc.nextInt();
		boolean found = binary_search(ar, n, target);
		if(found) {
			System.out.println("Element found!");
		} else {
			System.out.println("Element not found!");
		}
	}
}