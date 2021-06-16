import java.util.*;
public class BobAndArrayQueries{
  private static  int N =500003;
  private static int Arr[]=new int[N];
  private static int Segtree[]=new int[4*N];
  public static void Update1(int s,int e,int tidx,int x){
    if (s==e){
      Arr[x]++;
      Segtree[tidx]++;
    }
    else{
    int mid=(s+e)/2;
    if(s<=x && x<=mid){
      Update1(s,mid,2*tidx,x);
    }else{
      Update1(mid+1,e,2*tidx+1,x);
    }
    Segtree[tidx]=Segtree[2*tidx]+Segtree[2*tidx+1];
  }
    
  }
  public static void Update2(int s,int e,int tidx,int x){
    if(s==e){
      if (Arr[x]==0)
        return;
      Arr[x]--;
      Segtree[tidx]--;
    }
    else{
      int mid=(s+e)/2;
    if(s<=x && x<=mid){
      Update2(s,mid,2*tidx,x);
    }else{
      Update2(mid+1,e,2*tidx+1,x);
    }
    Segtree[tidx]=Segtree[2*tidx]+Segtree[2*tidx+1];
  }
  }
  public static int Query(int s,int e,int tidx,int l,int r){
    if(r<s || e<l){
      return 0;
    }
    if(l<=s && e<=r){
      return Segtree[tidx];
    }
    int mid=(s+e)/2;
    int p1=Query(s,mid,2*tidx,l,r);
    int p2=Query(mid+1,e,2*tidx+1,l,r);
    return p1+p2;
  }
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    int Q=sc.nextInt();
    while(Q-->0){
      int type=sc.nextInt();
      if (type==1){
        int x=sc.nextInt();
        Update1(1,N,1,x);
      }else if(type==2){
        int x=sc.nextInt();
      Update2(1,N,1,x);
      }else{
        int l=sc.nextInt();
        int r=sc.nextInt();
        System.out.println(Query(1,N,1,l,r));
      }
    }
  }
}