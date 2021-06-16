import java.util.*;
public class Assignjobs{
	public static class job{
		char id;
		int deadline;
		int profit;
		public job(char id,int deadline,int profit){
			this.id=id;
			this.deadline=deadline;
			this.profit=profit;
		}
	}
	public static void main(String[] args) {
		ArrayList<job>arr=new ArrayList<>();
		arr.add(new job('a',2,100));
		arr.add(new job('b',1,19));
		arr.add(new job('c',2,27));
		arr.add(new job('d',1,25));
		arr.add(new job('e',3,15));
		jobScheduling(arr,3);
	}
	public static void jobScheduling(ArrayList<job>arr,int t){
		int n=arr.size();
		//sort the job according to desceasing order of profit
		Collections.sort(arr,(a,b)-> b.profit-a.profit);
		//to keep track of time slot
		//false->slot empty
		//true->slot full
		boolean[]result=new boolean[t];
		//store the result
		char job[]=new char[t];
		for (int i=0;i<n;i++){
			//find a free slot for the current job
			//we find the slot form the end
			//we take minimum here because we can have deadline=6 and time slot
			//can be 3 the we take minimum of those
			int j=Math.min(t-1,arr.get(i).deadline-1);
			for (;j>=0 ; j--) {
				if(result[j]==false){
					result[j]=true;
					job[j]=arr.get(i).id;
					break;
				}
			}
		}
		for (char jb:job) {
			System.out.println(jb+" ");
			
		}
	}
}