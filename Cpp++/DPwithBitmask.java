import java.util.*;
class DPwithBitmask{
	public static int CountSetBits(int n){
		int count=0;
		while(n>0){
			n=n& (n-1);
			count++;
		}
		return count;
	}
	public static long Mincost(long cost[][]){
		int n=cost.length;
		long dp[]=new long[(1<<n)];
		for (int i=0;i<(1<<n);i++) {
			dp[i]=Integer.MAX_VALUE;
		}
		dp[0]=0;
		for (int mask = 0; mask < (1<<n); mask++) {
			int Worker=CountSetBits(mask); 
			for (int j=0;j<n;j++){
				if(((mask>>j)&1)==1){
					continue;
				}else{
					dp[mask|(1<<j)]=Math.min(dp[mask|(1<<j)],dp[mask]+cost[Worker][j]);
				}
			}
			}
			return dp[(1<<n)-1];
		}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long Arr[][]=new long[n][n];
		for(int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				Arr[i][j]=sc.nextInt();
			}
		}
		System.out.println(Mincost(Arr));
	}
}