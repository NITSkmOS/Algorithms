
public class MergeSort 
{
	
	/**
	 * Sorts an array into increasing order using Merge Sort algorithm
	 * @param a The array of ints to sort
	 */
	public static void mergeSort(int[] a)
	{
		int[] tmp = new int[a.length];
		mergeSort(a, tmp,  0,  a.length - 1);
	}

	
	/**
	 * Splits the current array into smaller arrays recursively until they
	 * are the smallest size they can be, then merges them
	 * @param a	The array to sort
	 * @param tmp The array to copy the sorted values of a into
	 * @param left The left bound for the current section of the array
	 * @param right The right bound for the current section of the array
	 */
	private static void mergeSort(int [ ] a, int [ ] tmp, int left, int right)
	{
		if( left < right )
		{
			int center = (left + right) / 2;
			mergeSort(a, tmp, left, center);
			mergeSort(a, tmp, center + 1, right);
			merge(a, tmp, left, center + 1, right);
		}
	}

	
	/**
	 * Merges two sorted lists into one sorted array
	 * @param a The array to sort
	 * @param tmp The array to store the sorted values of a into
	 * @param left The left bound of the first section
	 * @param right The right bound of the first section
	 * @param rightEnd The right bound of the second section
	 */
    private static void merge(int[ ] a, int[ ] tmp, int left, int right, int rightEnd )
    {
    	
    	
        int leftEnd = right - 1;
        int k = left;
        int num = rightEnd - left + 1;

        while(left <= leftEnd && right <= rightEnd)
            if(a[left] <= a[right])
                tmp[k++] = a[left++];
            else
                tmp[k++] = a[right++];

        while(left <= leftEnd)    // Copy rest of first half
            tmp[k++] = a[left++];

        while(right <= rightEnd)  // Copy rest of right half
            tmp[k++] = a[right++];

        // Copy tmp back
        for(int i = 0; i < num; i++, rightEnd--)
            a[rightEnd] = tmp[rightEnd];
    }
}
