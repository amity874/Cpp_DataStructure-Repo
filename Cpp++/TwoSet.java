import java.util.*;
class TwoSet{
	private static int  mod=(int)10e9+7;
	public static void Test(int target,int n){
		if(target%2!=0){
			System.out.println(0);
			return ;
		}
		System.out.println(target);
		target/=2;
		int  dp[][]=new int[n][target+1];
		dp[0][0]=1;
		for (int i=1;i<n ;i++ ) {
			for (int j=0;j<=target ;j++ ) {
				dp[i][j]=dp[i-1][j];
				int left=(j-i);
				if(left>=0){
					dp[i][j]=(dp[i][j]%mod+dp[i-1][left]%mod)%mod;
				}
			}
		}
		System.out.println(dp[n-1][target]);
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int target=n*(n+1)/2;
		Test(target,n);
}
}
			
