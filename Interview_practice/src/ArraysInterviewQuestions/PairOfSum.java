package ArraysInterviewQuestions;

import java.util.Arrays;

public class PairOfSum {

    public static int[] pairOfSum(int[] arr,int num){
        for(int i = 0 ;i<arr.length;i++){
            for(int j=0;j<arr.length;i++){
                if(arr[i]+arr[j] == num){
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{0};
    }

    public static void main() {
        int[] arr2 = {2, 4, 5, 7, 10};
        int[] result = PairOfSum.pairOfSum(arr2, 12);
        System.out.println("Pair of Sum = " + Arrays.toString(result));
        System.out.println("@@@@##################@@@@");
    }
}
