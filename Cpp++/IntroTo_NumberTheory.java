import java.util.ArrayList;
import java.util.BitSet;
import java.util.Scanner;
public class IntroTo_NumberTheory{
    private static int mod=1000000007;
    private static ArrayList<Long>Primes=new ArrayList<>();
    public static void GetPrimt(long max){
        BitSet IsPrime=new BitSet(500005);
        IsPrime.set(2,500005);
        for(int i=2;i*i<=max;i++){
            if(IsPrime.get(i)){
                for(int j=i*i;j<=max;j+=i){
                    IsPrime.set(j,false);
                }
            }
        }
        for (int j=0;j<=max;j++){
            if (IsPrime.get(j)){
                Primes.add((long) j);
            }
        }
    }
    public static long Divfact(long n) {
        long result=1;
        for (int i=0;Primes.get(i)<=n;i++){
            long count=0;
            long k=Primes.get(i);
            while ((n/k)!=0){
                count=count+n/k;
                k=k*Primes.get(i);
            }
            result=((result%mod)*(count+1)%mod)%mod;
        }
        return result;
    }
    static class ExtendedEuclid{
        public long x;
        public long y;
        public long Gcd;
    }
    public static ExtendedEuclid GcdExtendedEuclid(long a, long b){
        if(b==0){
            ExtendedEuclid base=new ExtendedEuclid();
            base.Gcd=a;
            base.x=1;
            base.y=0;
            return base;
        }
       ExtendedEuclid temp=GcdExtendedEuclid(b,a%b);
        ExtendedEuclid ans=new ExtendedEuclid();
        ans.Gcd=temp.Gcd;
        ans.x=temp.y;
        ans.y=(temp.x-(a/b)*temp.y);
        return ans;
    }
    public static void SegmentedSieve(long n,long m){
        BitSet SegSieve=new BitSet((int) ((m-n)+1));
        SegSieve.set(0,(int) ((m-n)+1));
        if(n==1)n++;
        for (int j=0;Primes.get(j)*Primes.get(j)<=m;j++){
            long prime=Primes.get(j);
            long k=(n/prime)*prime;
            if(k<n){
                k+=prime;
            }
            for (;k<=m;k+=prime){
                if(k!=prime){
                    SegSieve.set((int) (k-n),false);
                }
            }
        }
        for (int a = (int) n; a<=m; a++){
            if (a==1)continue;
            if (SegSieve.get((int) (a-n))){
                System.out.println(a);
            }
        }
    }
    public static long ModInverse(long a,long b){
        long ans=GcdExtendedEuclid(a,b).x;
        return ((ans%b)+b)%b;
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0){
            long a,b,d;
            a=sc.nextLong();
            b=sc.nextLong();
            d=sc.nextLong();
            long g=GcdExtendedEuclid(a,b).Gcd;
            if(d%g!=0){
                System.out.println(0);
                continue;
            }
            if(d==0){
                System.out.println(1);
                continue;
            }
            long min_y=((d%a)*ModInverse(b,a))%a;
            long temp=(d/b);
            if(d<min_y*b){
                System.out.println(0);
            }
            else{
            long n=(temp-min_y)/a;
            System.out.println(n+1);
        }}
        }
    }