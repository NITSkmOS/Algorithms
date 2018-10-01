public class bubbleSORT {
 
    
    public static void main(String [] args){
    
        int i, j , swap;
        
        int [] arr = {3,2,1,5,1,2,6,6,8,4,9,12 ,0 ,34, 34,6,1,100}; // array to be sorted
    
            for(i = 0; i < arr.length; i ++){
                
                for(j = 0; j < arr.length - 1  ;j++){
                    
                    if(arr[j] > arr[j+1]){
                        
                        swap = arr[j];        // place the bigger number to swap
                        arr[j] = arr[j+1];    // place the smaller number
                        arr[j+1] = swap;      
                    
                    
                    }
                }
            }
            
            //Display the sorted array
            for(int x = 0 ; x < arr.length ; x ++){
            System.out.print(arr[x] + ", ");
            
            }
    }
}
