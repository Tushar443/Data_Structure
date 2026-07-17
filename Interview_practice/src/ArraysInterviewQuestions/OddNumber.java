package ArraysInterviewQuestions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class OddNumber {

    public static boolean getOddNumber(List<Integer> list){
        return !list.parallelStream().anyMatch(a-> a % 2 == 0);
    }

    public static void findAllOdd(List<Integer> list){
        List<Integer> collect = list.parallelStream().filter(a -> a % 2 == 0).collect(Collectors.toList());
        System.out.println(collect);
    }

    public static void main() {
        List<Integer> list = new ArrayList<>(Arrays.asList(45, 433, 489, 2323, 45, 5, 77,58,34,2,8));
        boolean value = OddNumber.getOddNumber(list);
        System.out.println("odd number = " + value);

        findAllOdd(list);
    }
}
