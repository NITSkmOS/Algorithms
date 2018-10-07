void mergearrays(int a[],int n1,int b[],int n2,int c[],int n3){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];k++;i++;
        }
        else if(a[i]>b[j]){
            c[k]=b[j];j++;k++;
        }
        else {
            c[k]=a[i];
            k++;
            c[k]=b[j];
            k++;i++;j++;
        }
    }
    
    while(i<n1)
    {
        c[k]=a[i];
        i++;k++;
    }
    while(j<n2)
    {
        c[k]=b[j];j++;k++;
    }
}

void mergeSort(int a[], int size){
	// Write your code here
	
	if(size<=1) return;
	
	int b[1000000];
	int c[1000000];
	
	int sb=size/2;
	int sc=size-size/2;
	
	for(int i=0;i<sb;i++) b[i]=a[i];
	
	for(int j=sb;j<size;j++) c[j-sb]=a[j];
	
	mergeSort(b,sb);
	mergeSort(c,sc);
	mergearrays(b,sb,c,sc,a,size);
        
}
