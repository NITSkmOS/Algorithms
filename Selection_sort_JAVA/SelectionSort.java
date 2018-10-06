//Made By NAMAN

package selectionsort;


public class SelectionSort {
    public static void SelectionSort(int a[]){
        for(int i=0;i<a.length;i++){
            int pos=i;
            for(int j=i+1;j<a.length;j++){
                if(a[pos]>a[j]){
                    pos=j;
                }
                if(pos!=i){
                    int temp=a[i];
                    a[i]=a[pos];
                    a[pos]=temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int a[]={77,32,87,12,99,1};
        System.out.println("Before Selection Sort");  
        for(int i=0;i<a.length;i++){  
            System.out.print(a[i]+" ");  
        }  
        System.out.println();  
          
        SelectionSort(a);//sorting array using selection sort  
         
        System.out.println("After Selection Sort");  
        for(int i:a){  
            System.out.print(i+" ");  
        }  
    }  
    
    
}
