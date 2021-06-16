import java.util.*;
public class NotaTringle{
	private static int LowerBound(int a[],int target){
		int l=-1,r=a.length;
		while((l+1)<r){
			int m=(l+r)>>>1;
			if(a[m]>=target){
				r=m;
			}
			else l=m;
		}
		return r;
	}
	private static void PrintArr(int Arr[]){
		for (int i=0;i<Arr.length ;i++ ) {
			System.out.print(Arr[i]);
		}
	}
	private static int UpperBound(int a[],int target){
		int l=-1,r=a.length;
		while((l+1)<r){
			int m=(l+r)>>>1;
			if(a[m]<=target)l=m;
			else r=m;
		}
		return l+1;
	}
	public static void main(String[] args) {
		int n;
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		while(true){
			int Arr[]=new int[n];
			for (int i=0;i<n;i++) {
				Arr[i]=sc.nextInt();
			}
			Arrays.sort(Arr);
			int ans=0;
			for (int i=0;i<n ;i++ ) {
				for (int j=i+1;j<n ; j++) {
					ans+=Arr.length-(UpperBound(Arr,Arr[i]+Arr[j]));
				}
			}
			System.out.println(ans);
			n=sc.nextInt();
			if(n==0)break;
		}
	}
}