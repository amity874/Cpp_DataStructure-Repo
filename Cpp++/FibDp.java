import java.util.*;
public class FibDp{
	private static int Mod=1000000007;
//Memoization technique//or top down dp
	public static int Fib(int n,int dp[]){
		if(n==0 || n==1)return n;
		if(dp[n]!=-1)return dp[n];
		int ans=Fib(n-1,dp)+Fib(n-2,dp);
		dp[n]=ans;
		return ans;
	}
	public static int FriendsParty(int n){
		int dp[]=new int[n+1];
		//we can use also n size array 
		//but to make one based indexing we use n+1 size array
		dp[1]=1;//one friend one way
		dp[2]=2;//two friends two way
		for (int i=3;i<=n ;i++) {
			dp[i]=dp[i-1]+(i-1)*dp[i-2];
		}
		return dp[n];
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n;
		n=sc.nextInt();
		int Arr[]=new int[n+1];
		for (int i=1; i<=n;i++ ) {
			Arr[i]=sc.nextInt();
		}
		int dp[]=new int[n+1];
		// dp[0]=1;
		// dp[1]=1;
		// for (int i=2;i<=n ;i++ ) {
		// 			for (int j=1;j<=6 ;j++ ) {
		// 				if(j>i)break;
		// 				dp[i]=(dp[i]%Mod +dp[i-j]%Mod)%Mod;
		// 			}
		// 		}		
		// System.out.println(dp[n]);
		dp[1]=0;
		dp[2]=Math.abs(Arr[1]-Arr[0]);
		for (int i=3;i<=n ;i++) {
			dp[i]=Math.min(dp[i-1]+Math.abs(Arr[i]-Arr[i-1]),dp[i-2]+Math.abs(Arr[i]-Arr[i-2]));
					}
					System.out.println(dp[n]);
	}
}