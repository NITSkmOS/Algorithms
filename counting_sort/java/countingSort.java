import java.io.;
import java.util.;


 public class Solution {

    public static void main(String[] args) {
         Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. 
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int[] ar=new int[n];
        for(int i=0;in;i++){
            ar[i]=s.nextInt();
        }
        Arrays.sort(ar);
        int tot=0;
        int[] count=new int[n];
        for(int x=0;x100;x++){
            for(int y=0;yn;y++){
                if(ar[y]==x)
                    tot++;
            }
            count[x]=tot;
            System.out.print(tot+ );
            tot=0;
        }
    }
 }
