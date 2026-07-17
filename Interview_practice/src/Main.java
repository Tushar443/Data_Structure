import ArraysInterviewQuestions.*;
import DivideAndConquerAlgorithm.*;
import DynamicProgramming.FibonaccoSeriesDynamic;
import GreedyAlgorithms.FractionalKnapSackProblem;
import LinkedListsInterviewQuestions.SumList;
import RecursionInterviewQuestions.*;
import SortingAlgorithms.SortingAlgorithms;
import StactAndQuesuesInterviewQuestions.InfixToPostFix;
import StringPractice.LongestCommonPrefix;
import StringPractice.RemoveStringDuplicate;
import StringPractice.ReverseString;
import StringPractice.ReverseStringPrefix;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
//        recursiveQuestions();
//        arrayQuestions();
//        LinkedListQuestions();
//        stringQuestion();
//        collectionQuestions();
//        practiceProgram();
//        StringWithNewKeyWord();
//        StackAndQueue();
//        TreesQuestions();
//        GreedyAlgorithms();
//        DivideAndConquerAlgo();
        DynamicProgramming();
//        SortingAlgoriths();
    }

    private static void SortingAlgoriths() {
        SortingAlgorithms.main();
    }

    private static void DynamicProgramming() {
//        FibonaccoSeriesDynamic.main();
        FindMinPath.main();
    }

    private static void DivideAndConquerAlgo() {
//        NumberFactor.main();
//        HouseRobber.main();
//        ConvertString.main();
//        LongestCommonSubsequence.main();
        MinimumCostToReachEnd.main();
    }

    private static void GreedyAlgorithms() {
        //Insertion Sort
        //Selection Sort
//        ActivitySelectionProblem.main();
//        CoinChangeProblem.main();
        FractionalKnapSackProblem.main();
    }

    private static void TreesQuestions() {
//        BinarySearchTree.main();
//        AVLTree.main();
//        BinaryHeap.main();
//        Trie.main();
//        BinarySearch.main();
    }


    private static void StackAndQueue() {
//        ThreeInOneStack.main();
//        SetOfStack.main();

//        QueueUsingStack.main();

//        AnimalQueue.main();

//        ThreeElevatorsProblem.main();

        InfixToPostFix.main();
    }

    private static void LinkedListQuestions() {
        SumList.main();
    }

    private static void StringWithNewKeyWord() throws NoSuchFieldException, IllegalAccessException {
        // String one = "abc";
        // String two = new String("abc");
        // String one = "abc";
        // String two = "abc";
        // String one = "abc";
        // String two = "?abc".substring(1);
        // two = two.intern();
        String one = "abc";
        String two = "abc".substring(1);
        System.out.println("One CharArray = " + showInternalCharArrayHashCode(one));
        System.out.println("Two CharArray = " + showInternalCharArrayHashCode(two));
        System.out.println("One Hashcode = " + System.identityHashCode(one));
        System.out.println("Two Hashcode = " + System.identityHashCode(two));
        System.out.println(one == two);
        System.out.println(one.equals(two));
        System.out.println(two);
    }

    private static int showInternalCharArrayHashCode(String s) throws NoSuchFieldException, IllegalAccessException {
        final Field value = String.class.getDeclaredField("value");
        value.setAccessible(true);
        return value.get(s).hashCode();
    }

    private static void practiceProgram() throws Exception {
//      getOutputProgram();
        exceptionExample();

    }

    private static void exceptionExample() throws Exception {
        class A {
            public void methodA() throws IOException {
//                Class temp = Class.forName(
//                        "gfg");
                System.out.println("Method A");
            }
        }
        class B extends A {
            @Override
            public void methodA() throws FileNotFoundException {
                FileReader file = new FileReader("file.txt");
//
//                // Trying to read a file that doesn't exist
//                System.out.println(file.read());
                System.out.println("Method B");
            }
        }
        A a = new B();
        a.methodA();
    }

    public static void getOutputProgram() {
//        class X {
//            static int i = 1111;   //After L1 =>2 ,  L3=>0,L2=> 2 ,L4=>6
//
//            static{
//                System.out.println("Static X");
//                i = i-- - --i;    //L1  1111 - 1109 = 2
//            }
//
//            {
//                System.out.println("Non-Static X");
//                i = i++ + ++i;    //L2  0 + 2 = 2
//            }
//        }
//
//        class Y extends X{
//            static{
//                System.out.println("Static Y");
//                i = --i - i--;    //L3  1 - 1 = 0
//            }
//            {
//                System.out.println("Non-Static Y");
//                i = ++i + i++;    //L4 3 + 3 = 6
//            }
//        }
//
//        class DriverClass{
//            public static void demo(){
//                Y y = new Y();
//                System.out.println(y.i);    //L5
//            }
//        }
//
//        DriverClass.demo();
    }

    private static void collectionQuestions() {


    }

    private static void stringQuestion() {
        ReverseString.main();

        RemoveStringDuplicate.main();

        ReverseStringPrefix.main();

        LongestCommonPrefix.main();

    }


    private static void arrayQuestions() {
        System.out.println("@@@@  Array Questions  @@@@");
        /**
         * Missing Num
         */
        MissingNumbers.main();

        /**
         * Pair of Sum
         */
        PairOfSum.main();

        /**
         * Rotate Matrix
         */
        RotateMatrix.rotateMatrix();

        /**
         *  Largest Positive Integer That Exists With Its Negative
         */
        LargestPositiveNumberWithNegativeNumber.main();

        /**
         * Only Odd Numbers in the List
         */
        OddNumber.main();
        /**
         * Integer to Binary
         */
        IntegerToBinary.main();

        FindCountOfInteger.main();
    }

    public static void recursiveQuestions() {
        System.out.println("@@@@  Recursion Questions  @@@@");
        /**
         * Fibonacci Series 0 1 1 2 3 5 8 13 21 34 55 89
         */
        int fibo = FibonacciSeries.fibo(4);
        System.out.println("Fibonacci Series sum =" + fibo);

        /**
         * RecursionInterviewQuestions.Factorial 4! = 4*3*2*1 = 24
         */
        int n = 5;
        int facto = Factorial.facto(n);
        System.out.println("factorial of number " + n + "! is= " + facto);

        /**
         * sum of digit 112 = 4
         */
        n = 1122;
        int sum = sumOfDigit.sumDigit(n);
        System.out.println("Sum of Digit = " + sum);
        /**
         * Power of number 2^4 = 2*2*2*2
         */
        int num = 3, power = 4;
        int ans = PowerOfNumber.powerOfNum(num, power);
        System.out.println("Power of " + num + " = " + ans);

        /**
         * Greatest Common Factor GCD 8,12 = 4
         */
//        ans = RecursionInterviewQuestions.GreatestCommonFactor.gcd(200,30000,2);
//        System.out.println("GCD = "+ans);

        /**
         * Decimal to Binary
         */
        num = DecimalToBinary.decimalToBinary(13);
        System.out.println("Decimal to Binary " + num);

        /**
         * Tower of Hanoi
         */

        TowerOfHanoi.main();
    }
}