import java.util.*;
public class TernarySearch{
	private static int Ternarysearch(int Arr[],int taget){
		int lo=0;
		int hi=Arr.length-1;
		while(lo<=hi){
			int m1=lo+(hi-lo)/3;
			int m2=hi-(hi-lo)/3;
			if(Arr[m1]==taget)return m1;
			if(Arr[m2]==taget)return m2;
			if(taget<Arr[m1]){
				hi=m1-1;
			}else if (taget>Arr[m2]) {
				lo=m2+1;
			}uryt7t7t7vt545674
			else{
				lo=m1+1;
				hi=m2-1;
			}
		}
		return -1;
	}
	public static void main(String[] args) {
		int Arr[]={5,6,77,8,88,9};
		System.out.println(Ternarysearch(Arr,88));
	}
}