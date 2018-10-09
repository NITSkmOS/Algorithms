
package SelectionShort;

public class SelectionShort {
    public static void main(String[] args) {
        
        int [] number = {8,3,4,7,2,6,5,1,10,9};
        Selection_Short(number);
    }
     public static void Selection_Short (int [] number){
        for (int i=0 ; i<number.length ;i++){
            int shortest = number[i];
                for (int j=i ; j<number.length ; j++){
                    if (number[j] <= number[i]){
                        number [i] = number [j];   
                        number[j] = shortest;
                        shortest = number[i];
                    }
                }
        }
      
        System.out.println("-- Selection Short --");
        for (int k=0; k<number.length ; k++){
            System.out.print(number[k]+" ");
        }
        System.out.println();
    }
}
