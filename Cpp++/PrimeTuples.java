import java.util.*;
public class PrimeTuples{
	 public static int N=1000001;
	public static void main(String[] args) {
		BitSet Prime=new BitSet(N);
		Prime.set(2, N);
		for (int i=2;i*i<=N;i++){
			if (Prime.get(i)){
				for (int j=i*i;j<=N ;j+=i){
					Prime.set(j,false);
				}
			}
		}
		int Ans[]=new int [N];
		int count=0;
		for (int i=5;i<N;i++ ){
			if(Prime.get(i)&& Prime.get(i-2)){
				count++;
			}
			Ans[i]=count;
		}
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		while(T-->0){
			int N=sc.nextInt();
			System.out.println(Ans[N]);
		}
	}
}