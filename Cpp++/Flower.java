import java.util.*;
class Flower{
private static  int  mod= 1000000007;
private static  int dp[]=new int [100005];

	public static int[] CountFlowers(int k){
		dp[0]=1;
		for (int i=1;i<=100000 ;i++ )
					if(i<k)dp[i]=dp[i-1];
			else{
				dp[i]=((dp[i-1]%mod)+(dp[i-k]%mod))%mod;
			}
		for (int i=1;i<=100000 ;i++ ) {
			dp[i]=((dp[i-1]%mod)+(dp[i]%mod))%mod;
		}
		return dp;
	}
		public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		int k=sc.nextInt();
		int Arr[]=CountFlowers(k);
		while(t-->0){
			int a=sc.nextInt();
			int b=sc.nextInt();
			System.out.println((dp[b]-dp[a-1]+mod)%mod);
		}
	}
}