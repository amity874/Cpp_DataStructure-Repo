import java.util.*;
class Frog2{
	private static int inf=(int)1e9;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int Arr[]=new int [n];
		for (int i=0;i<n;i++ ) {
			Arr[i]=sc.nextInt();
		}
		int dp[]=new int [n];
		dp[0]=0;
		// for (int i=1;i<n ;i++ ) {
		// 	dp[i]=inf;
		// }
		for (int i=1;i<n;i++) {
			for (int j=1;j<=k;j++ ) {
				if(i-j<0)break;
				dp[i]=Math.min(dp[i],dp[i-j]+Math.abs(Arr[i]-Arr[i-j]));
			}
		}
		System.out.println(dp[n-1]);
	}
}