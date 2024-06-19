package DynamicProgramming;

import java.util.ArrayList;
import java.util.HashMap;

public class FibonaccoSeriesDynamic {
    public static void main() {
        HashMap<Integer,Integer> memo = new HashMap<>();
        System.out.println(fiboBottomToTop(6,memo));
        System.out.println(fiboTopToBottom(6));
    }

    public static int fiboBottomToTop (int n , HashMap<Integer,Integer> memo){
        if(n==1){
            return 0;
        }
        if(n == 2){
            return 1;
        }
        if(!memo.containsKey(n)){
            memo.put(n,fiboBottomToTop(n-1,memo) + fiboBottomToTop(n-2,memo));
        }
        return memo.get(n);
    }

    // with tabulation
    public static int fiboTopToBottom(int n){
        ArrayList<Integer> tb = new ArrayList<>();
        tb.add(0);
        tb.add(1);
        for(int i = 2 ; i<n;i++){
            int tb1 = tb.get(i-1);
            int tb2 = tb.get(i-2);
            tb.add(tb1+tb2);
        }
        return tb.get(n-1);
    }
}
