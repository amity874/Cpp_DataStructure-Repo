import java.util.*;
public class RemovingDigit{
	    private static ArrayList<Long> Getdigit(int n) {
        ArrayList<Long> result = new ArrayList<Long>();
        while (n >=1) {
            if (n % 10 != 0){ result.add((long) (n % 10));}
            n = n / 10;
        }
        return result;
    }
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		if(n>9){
			long dp[]=new long[n+1];
			for (int j=1;j<=9 ;j++ ) {
				dp[j]=1;
			}
			for (int j=10;j<=n ;j++ ) {
				dp[j]=Integer.MAX_VALUE;
			}
			for (int i=10;i<=n;i++) {
				ArrayList<Long> Digit=Getdigit(i);
				for (int j=0;j<Digit.size();j++ ) {
					dp[i]=Math.min(dp[i],1+dp[(int) (i-Digit.get(j))]);
				}
			}
			System.out.println(dp[n]);
		}else{
			System.out.println(1);
		}

	}
}