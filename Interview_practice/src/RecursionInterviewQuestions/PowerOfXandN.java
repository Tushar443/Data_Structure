package RecursionInterviewQuestions;

public class PowerOfXandN {
    public static void main() {
        double x = 2.0;
        int n = 10;
        System.out.println("Power of X and N = "+powerOfX(x ,  n));
    }

    private static double powerOfX(double x, int n) {
         if( n == 1){
             return x;
         }
         x = x * powerOfX(x,--n);
//         System.out.println(x +" "+n);
         return x;
    }
}
