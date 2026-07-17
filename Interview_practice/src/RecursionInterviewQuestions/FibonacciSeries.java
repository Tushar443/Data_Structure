package RecursionInterviewQuestions;

public class FibonacciSeries {
    public static int fibo(int n){
//        System.out.print(n + " ");
        if (n < 0) {
            return -1;
        }
        if (n == 0 || n == 1) {
            return n;
        }
        return fibo(n-1) + fibo(n-2);
    }


}
