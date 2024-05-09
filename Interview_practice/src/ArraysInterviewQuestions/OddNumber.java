package ArraysInterviewQuestions;

import java.util.List;

public class OddNumber {

    public static boolean getOddNumber(List<Integer> list){
        return !list.parallelStream().anyMatch(a-> a % 2 == 0);
    }
}
