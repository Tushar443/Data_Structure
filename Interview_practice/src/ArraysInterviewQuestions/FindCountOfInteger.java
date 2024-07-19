package ArraysInterviewQuestions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class FindCountOfInteger {
    public static void main() {
        findCount();
    }

    private static void findCount(){
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(2,3,4,53,4,3,53,5,5,5,9));
        int[] intArr = {2,3,4,53,4,3,53,5,5,5,9};
        arr.stream().collect(Collectors.groupingBy(Integer::new,Collectors.counting())).entrySet().forEach((entry)->{
            System.out.println(entry.getKey()+" "+entry.getValue());
        });
        System.out.println("########");
        IntStream.of(intArr).boxed().collect(Collectors.groupingBy(Integer::new,Collectors.counting())).entrySet().forEach((entry)->{
            System.out.println(entry.getKey()+" "+entry.getValue());
        });
    }
}
