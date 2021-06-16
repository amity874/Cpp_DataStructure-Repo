import java.util.*;
class EditDistance{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String n=sc.nextLine();
		String m=sc.nextLine();
        int dp[][]=new int[n.length()+1][m.length()+1];
		dp[0][0]=1;//Base case
		for (int i=1;i<=n.length();i++ ){
			dp[i][0]=i;
		}
		for (int j=0;j<=m.length();j++ ) {
			dp[0][j]=j;
		}
		for (int i=1;i<=n.length();i++ ) {
			for (int j=1;j<=m.length();j++ ) {
				if(n.charAt(i-1)==m.charAt(j-1)){
					dp[i][j]=dp[i-1][j-1];//if ith and jth charecter are same
				}
				else{
					dp[i][j]=1+Math.min(Math.min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);//(Secquentially) 1-replecing 2-deleting 3-adding
				}
			}
		}
		System.out.println(dp[n.length()][m.length()]);
	}
}