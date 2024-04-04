package RecursionInterviewQuestions;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

public class GreatestCommonFactor {
    static List arr = new ArrayList();
    public static int gcd(int num1 , int num2,int n){
        int end = 0;
        if(num1 < num2 ){
            end = num2 /2;
        }else {
            end = num1/2;
        }
        if(end == n){
            return 1;
        }
        if((num1 % n == 0) && (num2 % n == 0)){
            arr.add(n);
        }
        gcd(num1,num2,n+1);
        Collections.sort(arr);
        System.out.println(arr);
        if(arr.isEmpty()){
            return -1;
        }
        int size =arr.size()-1;
        return (int) arr.get(size);
    }

}
