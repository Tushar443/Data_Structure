package RecursionInterviewQuestions;

import java.util.ArrayList;
import java.util.List;

public class DecimalToBinary {

    static List<Integer> arr = new ArrayList<>();

    public static int decimalToBinary(int num){
        if(num < 0 ) return -1;
        if(num == 0) return 0;

        int remainder = num % 2;
        arr.add(remainder);

        return num % 2 + 10 * decimalToBinary(num/2);
    }
}
