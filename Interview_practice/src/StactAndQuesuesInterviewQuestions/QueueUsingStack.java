package StactAndQuesuesInterviewQuestions;

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

