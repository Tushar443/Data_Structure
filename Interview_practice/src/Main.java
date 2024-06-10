import ArraysInterviewQuestions.*;
import LinkedListsInterviewQuestions.SumList;
import RecursionInterviewQuestions.*;
import StactAndQuesuesInterviewQuestions.ShelterAnimal.AnimalQueue;
import StringPractice.RemoveStringDuplicate;
import StringPractice.ReverseString;
import TreesInterviewQuestions.BinarySearchTree.AVLTree;
import TreesInterviewQuestions.BinarySearchTree.BinaryHeap;
import TreesInterviewQuestions.BinarySearchTree.BinarySearchTree;

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
//        StactAndQueue();
        TreesQuestions();
    }

    private static void TreesQuestions() {
//        BinarySearchTree.main();
//        AVLTree.main();
        BinaryHeap.main();
    }

    private static void StactAndQueue() {
//        ThreeInOneStack.main();
//        SetOfStack.main();

//        QueueUsingStack.main();

//        AnimalQueue.main();
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
        String s = ReverseString.reverseString("Tushar");
        System.out.println(s);

        s = "tusadcsjlcnsekjdehusedsldheuiasscs,csejseoifsehfselfsehisehfeifsefucidewdssdshdsdassdddcsdsr";
        String s1 = RemoveStringDuplicate.removeDuplicate(s);
        System.out.println(s1);

        Map<Character, Integer> map = RemoveStringDuplicate.countOfChar(s);
//        System.out.println(map);
//        for (Map.Entry<Character,Integer> entry : map.entrySet()){
//            System.out.println(entry.getKey() + " "+ entry.getValue());
//        }
        Set<Character> set = map.keySet();
        for (Character c : set) {
            System.out.println("key = " + c + " and value = " + map.get(c));
        }
    }


    private static void arrayQuestions() {
        System.out.println("@@@@  Array Questions  @@@@");
        /**
         * Missing Num
         */
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 10};
        int miss = MissingNumbers.missingNum(arr);
        System.out.println("Missing Element from arr :- " + miss);
        System.out.println("@@@@##################@@@@");
        /**
         * Pair of Sum
         */
        int[] arr2 = {2, 4, 5, 7, 10};
        int[] result = PairOfSum.pairOfSum(arr2, 12);
        System.out.println("Pair of Sum = " + Arrays.toString(result));
        System.out.println("@@@@##################@@@@");
        /**
         * Rotate Matrix
         */
        RotateMatrix.rotateMatrix();

        /**
         * Largest Positive Integer That Exists With Its Negative
         * Input: nums = [-1,2,-3,3]
         * Output: 3
         * Explanation: 3 is the only valid k we can find in the array.
         */
        System.out.println("@@@@##################@@@@");
        int[] nums = new int[]{-49, 8, 19, -39, 37, 22, -39, 4, 37, 8, 20, -2, -4, -5, 14, -14, -27, 24, 30, 3, -12, 19, 22, 28, -3, -6, 6, 22, 37, 27, 16, 27, -6, -49, 31, 29};
        int resultMax = LargestPositiveNumberWithNegativeNumber.findMaxK(nums);
        System.out.println("largest number = " + resultMax);

        /**
         * Only Odd Numbers in the List
         */
        List<Integer> list = new ArrayList<>(Arrays.asList(45, 433, 489, 2323, 45, 5, 77));
        boolean value = OddNumber.getOddNumber(list);
        System.out.println("odd number = " + value);
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
    }
}