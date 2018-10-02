public class QuickSort {

	public static void quickSort(int[] input,int si,int ei){
		if(si>=ei)
			return;
		int pivot = getPivot(input,si,ei);
		quickSort(input, si, pivot-1);
		quickSort(input, pivot+1, ei);
	}
	public static int getPivot(int[] a, int si, int ei){
		int pivot = a[si];
		int c=0,i,j,t;
		for(i=si+1;i<=ei;i++){
			if(a[i]<=pivot)
				c++;
		}
		int pivot_pos = si+c;
		t = a[pivot_pos];
		a[pivot_pos] = a[si];
		a[si] = t;
		i=si;
		j=ei;
		while(i<pivot_pos && j>pivot_pos){
			if(a[i]>pivot){
				if(a[j]<=pivot){
					t=a[i];
					a[i]=a[j];
					a[j]=t;
					j--;
					i++;
				}
				else
					j--;
			}
			else
				i++;
		}
		return pivot_pos;

	}
	public static void main(String[] args) {
		int[] input = {5,9,2,1,0,8};
		quickSort(input, 0, input.length-1);
    System.out.println("Sorted Elements using quick sort are as follows");
		for(int i=0;i<input.length;i++)
			System.out.print(input[i]+"\t");

	}

}
