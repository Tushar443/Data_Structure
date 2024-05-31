package StactAndQuesuesInterviewQuestions;

import StactAndQuesuesInterviewQuestions.SetsOfStack.IStackNode;
import StactAndQuesuesInterviewQuestions.SetsOfStack.StackNode;

import java.util.Stack;

public class QueueUsingStack {

    public static void main(){
        QueueFromStack queueFromStack = new QueueFromStack();
        queueFromStack.enqueue(1);
        queueFromStack.enqueue(2);
        queueFromStack.enqueue(3);
        System.out.println(queueFromStack.dequeue());
        System.out.println(queueFromStack.dequeue());

    }

}

class QueueFromStack{
    Stack<Integer> newStack,oldStack;

    public QueueFromStack(){
       newStack = new Stack<>();
       oldStack = new Stack<>();
    }

    public void enqueue(int value){
       newStack.push(value);
    }

    public int dequeue(){
        if(oldStack.isEmpty()){
            while(!newStack.isEmpty()){
                int pop = newStack.pop();
                oldStack.push(pop);
            }
        }
       return oldStack.pop();
    }
}

class QueueD {
    int front;
    int back;
    String[] values;
    int size;

    public QueueD(int size){
        this.size = size;
        front=back=-1;
        values=new String[size];
    }

    public void enqueue(String value){
        if(front == -1 && back == -1){
            values[++back] = value;
            front++;
        }else{
            values[++back] = value;
        }
    }

    public String dequeue(){
        if(front != -1){
            return values[front++];
        }else{
            return "Empty";
        }
    }

    public boolean isAnimalDog(String animal){
        String value = values[front];
        return value==animal;
    }
}

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

