import java.util.Scanner;
public class CoinCombination {
    private static final int mod=1000000007;
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int x=sc.nextInt();
        long Coin[]= new long[n];
        for(int i=0;i<n;i++){
            Coin[i]=sc.nextInt();
        }
        long dp[]=new long[x+1];
        for (int i=0;i<=x;i++){
            dp[i]=0;
        }
        dp[0]=1;
        for(int i=1;i<=x;i++){
            for(int j=0;j<n;j++){
                if(Coin[j]>i)continue;
                dp[i]=(dp[i]+dp[(int) (i-Coin[j])])%mod;
            }
        }
        System.out.println(dp[x]);
    }
}