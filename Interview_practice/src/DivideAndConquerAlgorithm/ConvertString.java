package DivideAndConquerAlgorithm;

public class ConvertString {
    public static void main(){
        String s1 = "table";
        String s2 = "tbres";
        System.out.println(convertString(s1,s2));
    }

    public static int findMinOperation(String s1,String s2,int index1,int index2){
        if(index1 == s1.length()){
            return s2.length()-index2;
        }
        if(index2 == s2.length()){
            return s1.length() - index1;
        }
        if(s1.charAt(index1) == s2.charAt(index2)){
            return findMinOperation(s1, s2, index1+1, index2+1);
        }
        int deleteOp = 1+findMinOperation(s1, s2, index1+1, index2);
        int insertOp = 1+findMinOperation(s1, s2, index1, index2+1);
        int replaceOp = 1+findMinOperation(s1, s2, index1+1, index2+1);
        return Math.min(deleteOp, Math.min(insertOp,replaceOp));
    }

    public static int convertString(String s1 , String s2){
        return findMinOperation(s1,s2,0,0);
    }
}
