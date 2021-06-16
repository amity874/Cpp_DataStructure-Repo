import java.util.*;
public class BookShop{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int x=sc.nextInt();
		int Prices[]=new int[n+1];
		int Pages[]=new int[n+1];
		for (int i=1;i<=n ;i++ ) {
			Prices[i]=sc.nextInt();
		}for (int i=1;i<=n ;i++ ) {
			Pages[i]=sc.nextInt();
		}
		int dp[][]=new int[n+1][x+1];
		for (int i=1;i<=n ;i++ ) {
			for (int j=1;j<=x ;j++) {
				if(Prices[i]>j){
					dp[i][j]=dp[i-1][j];//If we have'nt budget
				}
				else{//if we have budget
					dp[i][j]=Math.max(dp[i-1][j],dp[i-1][j-Prices[i]]+Pages[i]);
				}
			}
		}
		System.out.println(dp[n][x]);
	}
}