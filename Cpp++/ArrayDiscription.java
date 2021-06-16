import java.util.Scanner;
public class ArrayDiscription{
    private static final int mod=1000000007;
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        long Arr[]=new long[n];
        for(int i=0;i<n;i++){
            Arr[i]=sc.nextInt();
        }
        long dp[][]=new long[m+1][n];
        for(int i=0;i<n;i++) {
            if (i == 0) {//first element
                if (Arr[i] != 0) dp[(int) Arr[i]][i] = 1;
                else {
                    for (int j = 1; j <= m; j++) {
                        dp[j][i] = 1;
                    }
                }
                continue;
            }
            if(Arr[i]!=0){
                dp[(int)Arr[i]][i]=dp[(int)(Arr[i]-1)][i-1]%mod+dp[(int) Arr[i]][i-1]%mod+
                        ((Arr[i]+1<=m)?dp[(int) (Arr[i]+1)][i-1]%mod:0);
            }else{
                for(int j=1;j<=m;j++){
                    dp[j][i]=dp[j][i-1];
                    dp[j][i]=dp[j][i]+dp[j-1][i-1];
                    if(j<m){
                        dp[j][i]=dp[j][i]%mod+dp[j+1][i-1]%mod;
                        // dp[j][i]=dp[j][i];
                    }
                }
            }
        }
        if(Arr[n-1]!=0){
            System.out.println(dp[(int) Arr[n-1]][n-1]%mod);
        }
        else {
            long result=0;
            for(int j=1;j<=m;j++){
                result=(result%mod+dp[j][n-1]%mod)%mod;
            }
            System.out.println(result);
        }
    }
}