import java.util.*;
 public class FlipH_to_T{
	public static void BuildSegtree(int Arr[],int segtree[],int start,int end,int tidx){
		if(start==end){
			segtree[tidx]=Arr[start];
			return;
		}
		int mid=(start+end)/2;
		BuildSegtree(Arr,segtree,start,mid,2*tidx);
		BuildSegtree(Arr,segtree,mid+1,end,2*tidx+1);
		segtree[tidx]=segtree[2*tidx]+segtree[2*tidx+1];
	}
	public static void Update(int Arr[],int Segtree[],int start,int end,int tidx,int idx,int val){
		if(start==end){
			Arr[idx]=val;
			Segtree[tidx]=val;
			return ;
		}
		int mid=(start+end)/2;
		if(idx>mid){
			Update(Arr,Segtree,mid+1,end,2*tidx+1,idx,val);
		}else{
			Update(Arr,Segtree,start,mid,2*tidx,idx,val);
		}
		Segtree[tidx]=Segtree[2*tidx]+Segtree[2*tidx+1];
	}
	public static int Querry(int SegTree[],int start,int end,int left,int right,int tidx){
		if(start>right||end<left){
			return 0;
		}
		if(start>=left&&end<=right){
			return SegTree[tidx];
		}
		int mid=(start+end)/2;
		return Querry(SegTree,mid+1,end,left,right,2*tidx+1)+Querry(SegTree,start,mid,left,right,2*tidx);
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int Arr[]=new int[n];
		for(int i=0;i<n;i++){
			Arr[i]=sc.nextInt();
		}
		System.out.println("NextInput");
		int SegTree[]=new int[4*n];
		BuildSegtree(Arr,SegTree,0,n-1,1);
		int q=sc.nextInt();
		while(q-->0){
			int querry=sc.nextInt();
			if(querry==1){
				int l=sc.nextInt();
				int m=sc.nextInt();
				System.out.println(Querry(SegTree,0,n-1,l,m,1));
			}else{
			int i=sc.nextInt();
			int v=sc.nextInt();	
				Update(Arr,SegTree,0,n-1,1,i,v);
			}
		}
		}
	}