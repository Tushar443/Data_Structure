package StactAndQuesuesInterviewQuestions;

import StactAndQuesuesInterviewQuestions.IStackNode;
import StactAndQuesuesInterviewQuestions.StackNode;

class StackD implements IStackNode {

    int size;
    int top;
    int[] values;

    public StackD(int size){
        top=0;
        this.size=size;
        values=new int[size];
    }

    public int getSize(){
        if(isEmpty()){
            return 0;
        }
        return size-top;
    }
    @Override
    public boolean isFull() {
        return top==size;
    }

    @Override
    public boolean isEmpty() {
        return top==0;
    }

    @Override
    public boolean push(int value) {
        if(!isFull()) {
            values[top++] = value;
            return true;
        }
        return false;
    }

    @Override
    public int pop() {
        if(isEmpty()){
            return -1;
        }else {
            int value = values[--top];
            values[top] =0;
            return value;
        }
    }

    @Override
    public int peek() {
        return values[top-1];
    }

    @Override
    public void join(StackNode before, StackNode after) {

    }
}