import java.util.*;
public class AssignMiceIntoHole{
	private static int Assign(ArrayList<Integer>Mice,ArrayList<Integer>Holes){
		if(Mice.size()!=Holes.size()){
			return -1;
		}
		//sort both entity
		Collections.sort(Mice);
		Collections.sort(Holes);
		int size=Mice.size();
		int maxsofar=0;
		for (int i=0;i<size ;i++ ) {
			int Time=Math.abs(Mice.get(i)-Holes.get(i));
			if(maxsofar<Time){
				maxsofar=Time;
			}
		}
		return maxsofar;
	}
	public static void main(String[] args) {
		ArrayList<Integer>Mice=new ArrayList<>();
		ArrayList<Integer>Holes=new ArrayList<>();
		Mice.add(-10);
		Mice.add(-79);
		Mice.add(-67);
		Mice.add(93);
		Mice.add(-85);
		Mice.add(-28);
		Mice.add(-94);
		//Holes
		Holes.add(-2);
		Holes.add(9);
		Holes.add(69);
		Holes.add(25);
		Holes.add(-39);
		Holes.add(23);
		Holes.add(50);
		System.out.println(Assign(Mice,Holes));
	}
}