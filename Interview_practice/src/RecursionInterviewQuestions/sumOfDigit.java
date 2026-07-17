package RecursionInterviewQuestions;

public class sumOfDigit {

    public static int sumDigit(int n){
        if (n < 0) {
            return -1;
        }
        if(n==0){
            return n;
        }
        return n % 10 + sumDigit(n/10);
    }
}
