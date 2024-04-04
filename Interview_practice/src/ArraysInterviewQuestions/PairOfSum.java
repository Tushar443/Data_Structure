package ArraysInterviewQuestions;

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
}
