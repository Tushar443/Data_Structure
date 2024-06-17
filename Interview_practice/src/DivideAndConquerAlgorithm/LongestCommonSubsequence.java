package DivideAndConquerAlgorithm;

public class LongestCommonSubsequence {
    public static void main(){
        System.out.println(findLongestCommonString("elephant" ,"erepat"));
    }

    public static int findLongString(String s1,String s2,int i1,int i2){
        if(s1.length() == i1 || s2.length()==i2){
            return 0;
        }
        int op1 = 0;
        if(s1.charAt(i1) == s2.charAt(i2)){
            op1 = 1 + findLongString(s1, s2, i1+1, i2+1);
        }
        int op2 = findLongString(s1, s2, i1+1, i2);
        int op3 = findLongString(s1, s2, i1, i2+1);
        return Math.max(op2,Math.max(op1,op3));
    }

    public static int findLongestCommonString(String s1,String s2){
        return findLongString(s1, s2,0,0);
    }
}
