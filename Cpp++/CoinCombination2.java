import java.util.*;
class CoinCombination2{
    private static final int mod=1000000007;
	public static void main(String[] args) {
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	int x=sc.nextInt();
	long coins[]=new long[n];
	for (int i=0;i<n ;i++ ){
		coins[i]=sc.nextInt();
	}
	long dp[]=new long[x+1];
	dp[0]=1;
	for (int i=0;i<n;i++ ) {
		for (int j=1;j<=x ;j++ ) {
			if(coins[i]>j)continue;
			dp[j]=(dp[j]+dp[(int) (j-coins[i])])%mod;
		}
	}
	System.out.println(dp[x]%mod);
	}
}