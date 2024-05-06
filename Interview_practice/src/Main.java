import ArraysInterviewQuestions.MissingNumbers;
import ArraysInterviewQuestions.PairOfSum;
import ArraysInterviewQuestions.RotateMatrix;
import RecursionInterviewQuestions.*;
import StringPractice.ReverseString;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //recursiveQuestions();
        arrayQuestions();
        //stringQuestion();
        collectionQuestions();
    }

    private static void collectionQuestions() {
        

    }

    private static void stringQuestion() {
        String s = ReverseString.reverseString("Tushar");
        System.out.println(s);


    }

    private static void arrayQuestions() {
        System.out.println("@@@@  Array Questions  @@@@");
        /**
         * Missing Num
         */
        int[] arr = {1,2,3,4,5,6,7,8,10};
        int miss = MissingNumbers.missingNum(arr);
        System.out.println("Missing Element from arr :- "+miss);
        /**
         * Pair of Sum
         */
        int [] arr2 = {2,4,5,7,10};
        int[] result = PairOfSum.pairOfSum(arr2,12);
        System.out.println(Arrays.toString(result));
        /**
         * Rotate Matrix
         */
        RotateMatrix.rotateMatrix();
    }

    public static void recursiveQuestions(){
        System.out.println("@@@@  Recursion Questions  @@@@");
        /**
         * Fibonacci Series 0 1 1 2 3 5 8 13 21 34 55 89
         */
        int fibo = FibonacciSeries.fibo(4);
        System.out.println("Fibonacci Series sum =" + fibo);

        /**
         * RecursionInterviewQuestions.Factorial 4! = 4*3*2*1 = 24
         */
        int n= 5;
        int facto = Factorial.facto(n);
        System.out.println("factorial of number "+n+"! is= "+facto);

        /**
         * sum of digit 112 = 4
         */
        n = 1122;
        int sum = sumOfDigit.sumDigit(n);
        System.out.println("Sum of Digit = "+sum);
        /**
         * Power of number 2^4 = 2*2*2*2
         */
        int num = 3 ,power = 4;
        int ans = PowerOfNumber.powerOfNum(num,power);
        System.out.println("Power of "+num+" = "+ ans);

        /**
         * Greatest Common Factor GCD 8,12 = 4
         */
//        ans = RecursionInterviewQuestions.GreatestCommonFactor.gcd(200,30000,2);
//        System.out.println("GCD = "+ans);

        /**
         * Decimal to Binary
         */
        num = DecimalToBinary.decimalToBinary(13);
        System.out.println("Decimal to Binary "+num);
    }
}