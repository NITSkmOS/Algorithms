public class heap_sort {

	public static void main(String[] args) {
		int heap[] = {5,1,9,2,0,6};
		for(int i=0;i<heap.length;i++)
			InsertIntoVirtualHeap(heap, i);
		for(int i=0;i<heap.length;i++)
			heap[heap.length-1-i] = removeMinfromVirtualHeap(heap,heap.length-i);
		for(int i=0;i<heap.length;i++)
			System.out.print(heap[i]+" ");
	}

	private static void InsertIntoVirtualHeap(int[] heap,int i) {
		int childIndex = i;
		int parentIndex = (childIndex-1)/2;
		while(childIndex>0) {
			if(heap[childIndex]<heap[parentIndex]) {
				int temp = heap[childIndex];
				heap[childIndex] = heap[parentIndex];
				heap[parentIndex] = temp;
				childIndex = parentIndex;
				parentIndex = (childIndex-1)/2;
			}
			else
				return;
		}
	}

	private static int removeMinfromVirtualHeap(int[] heap, int size) {

		int min = heap[0];
		heap[0] = heap[size -1];
		size--;
		int index = 0;
		int leftChildIndex = 1;
		int rightChildIndex = 2;

		while(leftChildIndex < size) {

			int minIndex = index;
			if(heap[leftChildIndex] < heap[minIndex])
				minIndex = leftChildIndex;
			if(rightChildIndex<size && heap[rightChildIndex]<heap[minIndex])
				minIndex = rightChildIndex;

			if(minIndex == index)
				break;
			else {
				int temp = heap[minIndex];
				heap[minIndex] = heap[index];
				heap[index] = temp;
				index = minIndex;
				leftChildIndex = 2 * index + 1;
				rightChildIndex = 2 * index + 2;
			}
		}
		return min;
	}



}
