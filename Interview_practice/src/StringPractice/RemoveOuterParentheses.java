package StringPractice;

import java.util.Stack;

public class RemoveOuterParentheses {

    public static void main(){
        String s = "(()())(())(()(()))";
//        removeOuter(s);
        removeOuterParanthesesAlternate(s);
    }

    private static String removeOuterParanthesesAlternate(String s){
        StringBuilder stringBuilder = new StringBuilder();
        int level = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                if (level++ > 0) stringBuilder.append(c);
            } else if (c == ')') {
                if (--level > 0) stringBuilder.append(c);
            }
        }
        return stringBuilder.toString();
    }

    private static String removeOuter(String s){
        Stack<Character> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for(int i = 0 ;i<s.length();i++){
            char c = s.charAt(i);
            // System.out.println("char = "+c +" size = "+ stack.size());
            if(c == '('){
                if(!stack.isEmpty()){
                    sb.append(c);
                }
                stack.push(c);
            }else if(c == ')'){
                if(stack.size() == 1 && stack.peek() == '('){
                    stack.clear();
                }else{
                    stack.pop();
                    sb.append(c);
//                    sb.append(c);
                }
            }
            System.out.println("char = "+c +" size = "+ stack.size());
        }
        return sb.toString();
    }
}
