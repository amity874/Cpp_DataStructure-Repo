import java.util.Arrays;
import java.util.Scanner;
public class Aggressive_cows {
    private static boolean ISvalid(int Arr[],int cows,int mid){
        int count=1;
        int lastposition=Arr[0];
        for (int i=1;i<Arr.length; i++){
            if (Arr[i]-lastposition>=mid){
                count++;
                lastposition=Arr[i];
            }
            if(count==cows)return true;
        }
        return false;
    }
    private static int distributionOfCows(int Arr[],int cows){
        Arrays.sort(Arr);
        int high=Arrays.stream(Arr).max().getAsInt();
        int low=1;
        int result=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ISvalid(Arr,cows,mid)){
                low=mid+1;
                result=mid;
            }else{
                high=mid-1;
            }
        }
        return  result;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        int Arr[]={}
}
