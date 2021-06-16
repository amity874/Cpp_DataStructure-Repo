import java.util.*;
public class SegmentedTree{
	public static void BuildSegmentedTreee(int Arr[],int SegTree[],int start,int end,int tidx){
		//Base case
		if(start==end){
			SegTree[tidx]=Arr[start];
			return;
		}
		int mid=(start+end)/2;
		//Recursive task
		BuildSegmentedTreee(Arr,SegTree,start,mid,2*tidx);
		BuildSegmentedTreee(Arr,SegTree,mid+1,end,2*tidx+1);	
		SegTree[tidx]=SegTree[2*tidx]+SegTree[2*tidx+1];
	}
	public static void Update(int Arr[],int SegTree[],int start,int end,int tidx,int idx,int val){
		//Base case
		if(start==end){
			Arr[idx]=val;
			SegTree[tidx]=val;
			return;
		}
		int mid=(start+end)/2;
		if(idx>mid){
			//Recursive task
			Update(Arr,SegTree,mid+1,end,2*tidx+1,idx,val);
		}
		else{
			//Recursive task
			Update(Arr,SegTree,start,mid,2*tidx,idx,val);
		}
		//self work
		SegTree[tidx]=SegTree[2*tidx]+SegTree[2*tidx+1];
	}
	public static int Query(int SegTree[],int start,int end,int tidx,int left,int right){
		//left Right denote our query range
		if(start>right || end<left){
			//Complete outside
			return 0;
		}
		if(start>=left && end<=right){
			return SegTree[tidx];
		}
		int mid=(start+end)/2;
		int a1=Query(SegTree,start,mid,2*tidx,left,right);
		int a2=Query(SegTree,mid+1,end,2*tidx+1,left,right);
		return a1+a2;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int Arr[]=new int[n];
		for (int i=0;i<n ;i++ ) {
			Arr[i]=sc.nextInt();
		}
		int Segtree[]=new int[4*n];
		BuildSegmentedTreee(Arr,Segtree,0,n-1,1);
		int q=sc.nextInt();
		while(q-->0){
			int type=sc.nextInt();
			if(type==1){
				int l=sc.nextInt();
				int r=sc.nextInt();
				System.out.println(Query(Segtree,0,n-1,1,l,r));
			}
			else{
				int i=sc.nextInt();
				int v=sc.nextInt();
				Update(Arr,Segtree,0,n-1,1,i,v);
			}

		}
	}
}