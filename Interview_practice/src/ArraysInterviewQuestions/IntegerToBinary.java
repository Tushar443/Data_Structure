package ArraysInterviewQuestions;

import java.util.ArrayList;

public class IntegerToBinary {
    public static void main(){
        integerToBinary(45);
    }

    private static void integerToBinary(int value){
        ArrayList<Integer> arr = new ArrayList<>();

        while (value > 0){
            arr.add(value%2);
            value=value/2;
        }
        System.out.println(arr);
    }
}
