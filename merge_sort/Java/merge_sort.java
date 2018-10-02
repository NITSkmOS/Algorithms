public class merge_sort {

	public static void mergeSort(int input[],int si,int ei){
		if(si>=ei)
			return;
		int mid= (si+ei)/2;
		mergeSort(input, si,mid);
		mergeSort(input,mid+1,ei);
		merge(input,si,ei);
	}

	private static void merge(int[] input, int si, int ei) {
		int mid=(si+ei)/2;
		int ans[]=new int[ei-si+1];
		int i=si;
		int j=mid+1;
		int k=0;
		while(i<=mid && j<=ei){
			if(input[i]<input[j]){
				ans[k]=input[i];
				i++;
				k++;
			}
			else{
				ans[k]=input[j];
				j++;
				k++;
			}
		}
		while(i<=mid){
			ans[k]=input[i];
			i++;
			k++;
		}
		while(j<=ei){
			ans[k]=input[j];
			k++;
			j++;
		}
		for(int l=0;l<ans.length;l++)
			input[si+l]=ans[l];
	}

	public static void main(String args[]){
		int input[]={5,1,0,3};
		mergeSort(input, 0, input.length-1);
    System.out.println("Sorted Elements using merge sort are as follows");
		for(int i=0;i<input.length;i++)
			System.out.print(input[i]+"\t");
		System.out.println();
	}
}
