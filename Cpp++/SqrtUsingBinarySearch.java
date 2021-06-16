import java.util.*;
public class SqrtUsingBinarySearch{
	private static int Sqrt(int n){
		int lo=0;
		int hi=n-1;
		int potentialCand=-1;
		while(lo<=hi){
			int mid=lo+(hi-lo)/2;
			if(mid*mid==n)return mid;  //perfect Square
			else if(mid*mid>n){
				hi=mid-1;
			}
			else{
				potentialCand=mid;
				lo=mid+1;
			}
		}
		return potentialCand;
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			int n=sc.nextInt();
			System.out.println(Sqrt(n));
		}
	}
}