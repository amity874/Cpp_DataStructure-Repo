import java.util.*;
public class GcdAndLcm{
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        Map<Integer, Integer> mp = new HashMap<>();
        while (T-- > 0) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (mp.containsKey(x)) {
                    mp.put(x, mp.get(x) + 1);
                } else {
                    mp.put(x, 1);
                }

            }
            long ans = 0;
            for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
                if (mp.containsKey(2*entry.getKey())){
                    ans += mp.get(entry.getKey()) * (mp.get(2*entry.getKey()));
//                    System.out.print(entry.getKey() + " " + entry.getValue());
                }

            }
            System.out.println(ans);
            mp.clear();
        }
}
}