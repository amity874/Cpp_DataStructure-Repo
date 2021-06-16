import java.util.*;
class RectangleCutting{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		long dp[][]=new long[a+1][b+1];
		for (int i=1;i<=a;i++){
			for (int j=1;j<=b;j++ ) {
				dp[i][j]=Integer.MAX_VALUE;
			}
		}
		for (int i=0;i<=a;i++) {
			for (int j=0;j<=b;j++) {
				if(i==j)//No cuts needed
				{
					dp[i][j]=0;

				}else{
				//horijontal cut
					for (int k=1;k<j;k++) {
						dp[i][j]=Math.min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
					}
				//Vertical cut
					for (int k=1;k<i;k++){
						dp[i][j]=Math.min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
					}
				}
			}
		}
		System.out.println(dp[a][b]);
	}
}