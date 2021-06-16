import java.util.*;
class Project{
	public static class jobs{
		int  start;
		int  end;
		int  profit;
		public jobs(int  start ,int  end,int profit){
			this.start=start;
			this.end=end;
			this.profit=profit;
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		ArrayList<jobs>Arr=new ArrayList<>();
		for (int i=0;i<n ; i++){
			Arr.get(i).start=sc.nextInt();
		}
		Collections.sort(Arr,(a,b)->a.end-b.end);
		int dp[]=new int[(int n)n];
		dp[0]=Arr.get(0).profit;
	}
		
	}
