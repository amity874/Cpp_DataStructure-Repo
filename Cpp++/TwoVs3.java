import java.util.*;
import java.io.*;
class segtree{
 	public static int tree[];
 	public static int Arr[];
	public static int Power[]=new int[100001];
	public static int mod=3;
	int n;
	public segtree(int n,int a[]){
		this.n=n;
		Arr=a;
		tree=new int[4*n+1];
	}
	public static void Pow(){
		Power[0]=1;
		Power[1]=2;
		for (int i=2;i<=100000;i++){
			Power[i]=(Power[i-1]*2)%mod;
		}
	}
	public static void Build(int start,int end,int tidx){
		if(start==end){
			tree[tidx]=Arr[start];
			return;
		}
		int mid=(start+end)/2;
		Build(start,mid,2*tidx);
		Build(mid+1,end,2*tidx+1);
		tree[tidx]=(Power[(end-mid)]*tree[2*tidx]+tree[2*tidx+1])%mod;
	}
	public static int Query(int s,int e,int tidx,int left,int right){
		if(s>right || e<left){
			return 0;
		}
		if(s>=left && e<=right){
			return (tree[tidx]*Power[(right-e)])%mod;
		}
		int mid=(s+e)/2;
		int p1=Query(s,mid,2*tidx,left,right);
		int p2=Query(mid+1,e,2*tidx+1,left,right);
		return (p1+p2)%3;
	}
	public static void Update(int s,int e,int tidx,int idx,int val){
		if(s==e){
			Arr[idx]+=val;
			tree[tidx]+=val;
			return;
		}
		int mid=(s+e)/2;
		if(s<=idx&&idx<=mid){
			Update(s,mid,2*tidx+1,idx,val);
		}else{
			Update(s,mid,2*tidx,idx,val);
		}
		tree[tidx]=(Power[(e-mid)]*tree[2*tidx]+tree[2*tidx+1])%mid;
	}
}
public class TwoVs3{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int A[]=new int[N];
		String s=sc.next();
		for (int i=0;i<s.length();i++){
			if(s.charAt(i)=='1'){
				A[i]=1;
			}
		}
		segtree St=new segtree(N,A);
		St.Pow();
		St.Build(0,N-1,1);
		int Q=sc.nextInt();
		while(Q-->0){
			int type=sc.nextInt();
			if(type==0){
				int l=sc.nextInt();
				int r=sc.nextInt();
				System.out.println(St.Query(0,N-1,1,l,r));
			}else{
				int idx=sc.nextInt();
				if(A[idx]==1)continue;
				St.Update(0,N-1,1,idx,1);
			}
		}
	}
	}