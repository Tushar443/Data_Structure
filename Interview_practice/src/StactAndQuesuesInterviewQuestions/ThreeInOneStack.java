package StactAndQuesuesInterviewQuestions;

import java.util.ArrayList;
import java.util.List;

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
}
