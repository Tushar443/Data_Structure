package LinkedListsInterviewQuestions;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class SumList {

    public static void main(){
        List<Integer> ll1 = new LinkedList();
        List<Integer> ll2 = new LinkedList();
        List<Integer> sumList = new LinkedList();

        ll1.add(7);ll1.add(1);ll1.add(6);
        ll2.add(5);ll2.add(9);ll2.add(2);

        System.out.println(ll1);
        System.out.println(ll2);
        ListIterator lt1 = ll1.listIterator();
        ListIterator lt2 = ll2.listIterator();
        int carry = 0;
        while(lt1.hasNext() || lt2.hasNext()){
            int sum = Integer.parseInt(String.valueOf(lt2.next())) + Integer.parseInt(String.valueOf(lt1.next())) + carry;
            sumList.add(sum % 10);
            carry = sum/10;
        }

        System.out.println(sumList);
    }
}
