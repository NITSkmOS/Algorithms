public class Binary {
    public static void main(String[] args) {
        int[] arr = { 64,126,78,12,10,15,68,96 };
        System.out.println(rank(12, arr));
    }
    
    public static int rank(int val, int[] arr) {
        return rank(val, arr, 0, arr.length-1);
    }
    
    private static int rank(int val, int[] arr, int lo, int hi) {
        if (lo > hi) return -1;
        
        int mid = lo + (hi - lo) / 2;
        
        if (val < arr[mid]) {
            return rank(val, arr, lo, mid - 1);
        } else if (val > arr[mid]) {
            return rank(val, arr, mid + 1, hi);
        } else {
            return mid;
        }
    }
}