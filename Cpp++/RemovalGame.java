import java.util.*;
class RemovalGame{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int Arr[]=new int[n];
		for (int i=0;i<n ;i++ ) {
			Arr[i]=sc.nextInt();
		}
		long dp[][]=new long[n][n];
		for (int length=1;length<=n;length++ ) {
			for (int i=0;i+length<=n;i++){
				int j=i+length-1;
				long x=(i+2<=j)?dp[i+2][j]:0;
				long y=(i+1<=j-1)?dp[i+1][j-1]:0;
				long z=(i<=j-2)?dp[i][j-2]:0;

				dp[i][j]=Math.max(Arr[i]+Math.min(x,y),Arr[j]+Math.min(y,z));
			}
		}
		System.out.println(dp[0][n-1]);
	}
}