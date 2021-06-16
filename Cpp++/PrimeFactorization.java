import java.util.*;
import java.util.Arrays;
import java.util.Collections;
public class PrimeFactorization{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long n;
		n=sc.nextLong();
		TreeMap<Long ,Integer> factor=new TreeMap<>();//store <Prime,Poer> in pair
		for (long i=2;i<=n ;i++ ) {
			while(n%i!=0){
				factor.put((int)i);
				n/=i;
			}
		}
	}
}