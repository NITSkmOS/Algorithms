package lecture9;

public class QuickSort {

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
        quicksort(arr,0,arr.length-1);
        for(int i=0;i<arr.length;i++){
        	System.out.print(arr[i]+" ");
        }
	}
	public static void quicksort(int arr[],int low, int high){
		if(low>=high){
			return;
		}
		int left=low;
		int right=high;
		int mid=(low+high)/2;
		int pivot=arr[mid];
		while(left<=right){
			while(arr[left]<pivot){
				left++;
			}
			while(arr[right]>pivot){
				right--;
			}
			if(left<=right){
				int temp=arr[left];
				arr[left]=arr[right];
				arr[right]=temp;
				left++;
				right--;
				}
		}
		quicksort(arr,low,right);
		quicksort(arr,left,high);
	}

}
