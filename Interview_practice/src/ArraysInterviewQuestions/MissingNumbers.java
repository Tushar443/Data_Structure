package ArraysInterviewQuestions;

public class MissingNumbers {
    public static void main(){
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 10};
        int miss = MissingNumbers.missingNum(arr);
        System.out.println("Missing Element from arr :- " + miss);
        MissingNumbers.missingMultipleValueFromArray(arr);
        System.out.println("@@@@##################@@@@");


    }
    public static int missingNum(int[] arr){
        int len = arr.length-1;
        int lastNum = arr[len];
        int actualSum = lastNum * (lastNum+1) /2;

        int sum = 0;
        for(int i : arr){
            sum+=i;
        }

        int miss = actualSum - sum;
        return miss;
    }

    public static void missingMultipleValueFromArray(int[] seq){
        int add= 1;
        for(int i =0;i<seq.length;i++){
            if(seq[i] == add){
                System.out.println(seq[i]);
            }else{
                System.out.println(add + "Not Present ");
                i--;
            }
            add+=1;
        }
    }
}
