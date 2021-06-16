import java.util.*;
class GridPath{
    private static final int mod=1000000007;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int Arr[][]=new int[n][n];
		for (int i=0;i<n ;i++ ) {
			for (int j=0;j<n;j++ ) {
				char ch=sc.next().charAt(0);
				Arr[i][j]=(ch=='.')?1:0;
			}
		}
		int dp[][]=new int[n][n];
		if (Arr[n-1][n-1]==1){
			dp[n-1][n-1]=1;
		}
		for (int i=n-2;i>=0;i--){//Filling last column;
			if(Arr[i][n-1]==0)dp[i][n-1]=0;
			else{
				dp[i][n-1]+=dp[i+1][n-1];
			}
		}
		for (int i=n-2;i>=0 ;i--){//last row
			if(Arr[n-1][i]==0)dp[n-1][i]=0;
			else{
				dp[n-1][i]+=dp[n-1][i+1];
			}
		}
		for (int i=n-2;i>=0;i--){
			for (int j=n-2;j>=0 ;j-- ) {
				if(Arr[i][j]==0)dp[i][j]=0;
				else{
					dp[i][j]+=(dp[i+1][j]%mod+dp[i][j+1]%mod)%mod;
				}
			}
		}
		System.out.println(dp[0][0]);
	}
}