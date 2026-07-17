package RecursionInterviewQuestions;

public class Factorial {

    public static int facto(int n){
        if(n<1){
            return -1;
        }
        if(n==0 || n==1){
            return n;
        }
        return n * facto(n-1);
    }
}
