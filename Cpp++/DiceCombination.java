import java.util.*;
class DiceCombination{
	private static int mod=1000000007;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int dp[]=new int[n+1];
		dp[0]=1;
		dp[1]=1;
		for (int i=2; i<=n;i++ ) {
			for (int j=1;j<=6 ;j++ ) {
				if(j>i)continue;
				dp[i]=(dp[i]%mod+dp[i-j]%mod)%mod;
			}
		}
		System.out.println(dp[n]);
	}
}