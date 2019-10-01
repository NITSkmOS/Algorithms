import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MagicGrid {
	
	public static void main(String[] args)throws IOException, NumberFormatException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t-->0){
        String k[]=br.readLine().trim().split(" ");
        int n=Integer.parseInt(k[0]);
        int m=Integer.parseInt(k[1]);
        int a[][]=new int[n][m];
        for(int i=0;i<n;i++){
            k=br.readLine().trim().split(" ");
            for(int j=0;j<m;j++)
                a[i][j]=Integer.parseInt(k[j]);
        }
        System.out.println(calc(a,n,m));
        }        
        br.close();
	}
    
    public static int calc(int a[][],int n,int m){
        int dp[][]=new int[n][m];
        dp[n-1][m-1]=1;
        for(int i=n-2;i>=0;i--)
            dp[i][m-1]=Math.max(0,dp[i+1][m-1]-a[i][m-1]);
        for(int j=m-2;j>=0;j--)
            dp[n-1][j]=Math.max(0,dp[n-1][j+1]-a[n-1][j]);
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int min=Math.min(dp[i+1][j],dp[i][j+1]);
                if(a[i][j]>0)
                    dp[i][j]=(a[i][j]>min)?0:min-a[i][j];
                else
                    dp[i][j]=min-a[i][j];
                if(dp[i][j]==0)
                	dp[i][j]++;
            }
        }
        return dp[0][0];
    }

}
