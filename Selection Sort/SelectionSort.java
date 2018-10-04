public class SelectionSort {
  public static void sort(int[] input) {

        int inputLength = input.length;

        for (int i = 0; i < inputLength - 1; i++) {

            int min = i;
            for (int j = i + 1; j < inputLength; j++) {
                if (input[j] < input[min]) {
                    min = j;
                }
            }
            int temp = input[i];
            input[i] = input[min];
            input[min] = temp;
        }

    }

}
