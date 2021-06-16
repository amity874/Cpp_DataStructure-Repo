import java.util.*;
public class ActivitySelection{
	public static class Activity{
		int start ;
		int finish;
		public Activity(int start,int finish){
			this.start=start;
			this.finish=finish;
		}
	}
	public static void main(String[] args) {
		
		ArrayList<Activity>arr=new ArrayList<>();
		arr.add(new Activity(5,9));
		arr.add(new Activity(1,2));
		arr.add(new Activity(3,4));
		arr.add(new Activity(0,6));
		arr.add(new Activity(5,7));
		arr.add(new Activity(8,9));
		PrintActivity(arr,arr.size());
	}
	private static void PrintActivity(ArrayList<Activity> arr,int len){
		//Sorting on the basis of finish time(asceasing order of profit
		// Collections.sort(arr,(a,b)-> b.profit-a.profitending order)
		Collections.sort(arr,(a,b)->a.finish-b.finish);
		int i=0;
		System.out.println("("+arr.get(i).start+" ,"+arr.get(i).finish+")");
		for (int j=1;j<len; j++) {
			 if(arr.get(j).start>=arr.get(i).finish){
			 	System.out.println("("+arr.get(j).start+" ,"+arr.get(j).finish+")");
			 	i=j;
			 }
		}
	}
}