import java.util.*;
class MoneySum{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		TreeSet<Integer> result=new TreeSet<Integer>();
		while(n-->0){
			int x=sc.nextInt();
			if(result.size()==0){
				result.add(x);
				continue;
			}
			ArrayList<Integer>temp=new ArrayList<Integer>(); 
			for (Integer it:result){
				temp.add(it+x);
			}
			result.add(x);
			for (int i=0;i<temp.size();i++ ) {
				result.add(temp.get(i));
			}
		}
		System.out.println(result.size());
		for (Integer it:result){
			System.out.println(it+" ");
		}
	}
}
