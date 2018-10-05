
public class InsertionSort {
	
	/**
	 * Sorts an array of doubles into ascending order using the insertion
	 * sort algorithm. O(n^2)
	 * @param a The array of doubles to sort into ascending order
	 */
	public static double[] insertionSort(double a[])
    {
		double[] arr = new double[a.length];
		for(int i = 0; i < a.length; i++) {
			arr[i] = a[i];
		}
		
        int n = arr.length;
        for (int i = 1; i < n; i++)
        {
            double key = arr[i];
            int j = i - 1;
 
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return arr;
    }
}
