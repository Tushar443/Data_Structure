package StactAndQuesuesInterviewQuestions;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;

public class InfixToPostFix {
    public static void main(){
        String s = "a+b*(c-d)";  // abcd-*+
        infixToPostFix(s);
    }
    public static void infixToPostFix(String infix){
        Deque<Character> deque = new ArrayDeque<>();
        ArrayList<Character> op = new ArrayList<>(Arrays.asList('+','*','/','-'));
        for(int i = 0;i<infix.length();i++){
            char value = infix.charAt(i);
            if(value == '(' || value == ')') continue;
            if(op.contains(value)){
                deque.addLast(value);
            }else{
                deque.addFirst(value);
            }
        }
        System.out.println(deque);
    }


}
