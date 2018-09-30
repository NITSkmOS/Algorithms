package bubblesort;

import java.util.ArrayList;
import java.util.Arrays;

public class BubbleSort {

	public ArrayList<Integer> bubbleSort(ArrayList<Integer> arrli) {
		
		/*
		 * Function to do bubble sort.
		 * 
		 * :param arrli: A list of element to sort.
		 */
		boolean swapped;
		int temporary;
		int j = 1;
		do {
			swapped = false;
			for (int i = 0; i < arrli.size() - j; i++) {
				if (arrli.get(i) > arrli.get(i + 1)) {
					temporary = arrli.get(i + 1);
					arrli.set(i + 1, arrli.get(i));
					arrli.set(i, temporary);
					swapped = true;
				}

			}
			j++;
		} while (swapped || j == 1);
		return arrli;
	}
	
	
	public static void main(String[] args) {
		BubbleSort nb = new BubbleSort();
		ArrayList<Integer> arrli = new ArrayList<Integer>(Arrays.asList(6, 5, 4, 3, 2, 1));
		arrli = nb.bubbleSort(arrli);
		String joined = String.join(", ", arrli.toString());
		System.out.print("Sorted elements using Bubble Sort:\n"+joined);
		
	}

}
