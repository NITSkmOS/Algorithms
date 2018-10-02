public class ExampleHeapSort {
    public static void main(String[] args) {
        int[] numbers = { 14, 6, 9, 4, 56, 34, 21, 39 };
        heapsort(numbers);
        for (int h = 0; h < numbers.length; h++)
            System.out.print(numbers[h]+ " ");
    }
  
    public static void heapsort(int[] a) {
        for (int i = a.length / 2 - 1; i >= 0; i--)
            shiftDown(a, i, a.length);
        for (int i = a.length - 1; i > 0; i--) {
            swap(a, 0, i);
            shiftDown(a, 0, i);
        }
    }
  
    private static void shiftDown(int[] a, int i, int n) {
        int child;
        int tmp;
  
        for (tmp = a[i]; leftChild(i) < n; i = child) {
            child = leftChild(i);
            if (child != n - 1 && (a[child] < a[child + 1]))
                child++;
            if (tmp < a[child])
                a[i] = a[child];
            else
                break;
        }
        a[i] = tmp;
    }
  
    private static int leftChild(int i) {
        return 2 * i + 1;
    }
  
    public static void swap(int[] numbers, int i, int j) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}