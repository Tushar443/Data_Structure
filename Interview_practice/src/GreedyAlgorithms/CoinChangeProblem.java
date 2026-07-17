package GreedyAlgorithms;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.stream.Stream;

public class CoinChangeProblem {

    public static void main(){
        ArrayList<Integer> coins = new ArrayList<>();
        coins.add(1);
        coins.add(2);
        coins.add(50);
        coins.add(100);
        coins.add(20);
        coins.add(5);
        coins.add(10);
        coins.add(1000);
        int value  = 2035;
        System.out.println("Coins We need = "+CoinSortingAlgo(coins,value));
        CSA(coins,value);


    }

    private static int CoinSortingAlgo(ArrayList<Integer> coins, int value) {
        Comparator<Integer> com  = Comparator.comparingInt(Integer::intValue);
        Collections.sort(coins,com);
        int temp = value;
        int count = 0;
        int n = coins.size()-1;
        int i = n;
        while (temp > 0 && i >= 0){
            if(temp > coins.get(n)){
                i = n;
            }
            int currentValue = coins.get(i);
            if(currentValue <= temp){
                temp = temp - currentValue;
                count++;
            }
            i--;
        }
        return count;
    }

    //Version2
    private static void CSA(ArrayList<Integer> arr,int n){
        int index = arr.size()-1;
        while(true){
            int coinValue = arr.get(index);
            index --;
            int maxAmt = (n/coinValue)* coinValue;
            if(maxAmt > 0 ){
                System.out.println("count value = "+ coinValue + " count = "+ n/coinValue);
                n=n-maxAmt;
            }
            if(n==0) break;
        }
    }
}
