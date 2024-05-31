package StactAndQuesuesInterviewQuestions.ThreeInOneStack;

import java.util.Arrays;

public class ThreeInOneStack implements ThreeStack{
    int numberOfStack = 3;
    public int[] sizes;
    public int[] values;
    public int stackCapacity;



    public ThreeInOneStack(int size) {
        sizes = new int[numberOfStack];
        values = new int[size * numberOfStack];
        stackCapacity=size;
    }


    @Override
    public boolean isFull(int stackNum) {
        if(sizes[stackNum] == stackCapacity){
            return true;
        }
        return false;
    }

    @Override
    public boolean isEmpty(int stackNum) {
        if(sizes[stackNum] == 0){
            return true;
        }
        return false;
    }

    @Override
    public int topOfStack(int stackNum) {
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size -1;
    }

    @Override
    public void push(int stackNum, int value) {
        if(isFull(stackNum)){
            System.out.println("stack is full");
        }else{
            sizes[stackNum]++;
            values[topOfStack(stackNum)] = value;

        }
    }

    @Override
    public int pop(int stackNum) {
        if(isEmpty(stackNum)){
            System.out.println("stack is empty");
            return -1;
        }else{
            int topIndex=topOfStack(stackNum);
            int value = values[topIndex];
            values[topIndex] = 0 ;
            sizes[stackNum]--;
            return value;
        }
    }

    @Override
    public int peek(int stackNum) {
        if(isEmpty(stackNum)){
            System.out.println("Stack is Full");
            return -1;
        }else{
            return values[topOfStack(stackNum)];
        }
    }

    public static void main(){
        ThreeInOneStack threeInOneStack = new ThreeInOneStack(3);
        Arrays.stream(threeInOneStack.sizes).forEach(System.out::println);
        threeInOneStack.push(0,8);
        threeInOneStack.push(0,10);
        threeInOneStack.push(1,51);
        threeInOneStack.push(1,526);
        threeInOneStack.push(2,856);

        System.out.println("0st stack = " + threeInOneStack.isEmpty(0));
//        Arrays.stream(threeInOneStack.values).forEach(System.out::println);
//        Arrays.stream(threeInOneStack.sizes).forEach(System.out::println);
        System.out.println("0st peek = " +threeInOneStack.peek(0));
        System.out.println("1st top element = " +threeInOneStack.topOfStack(1));
    }
}
