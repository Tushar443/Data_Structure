package RecursionInterviewQuestions;

public class PowerOfNumber {
    public static int powerOfNum(int base,int exponential){
        if (exponential < 0) {
            return -1;
        }
        if(exponential==0 || exponential == 1){
            return base;
        }
        return base * powerOfNum(base,exponential-1);
    }
}
