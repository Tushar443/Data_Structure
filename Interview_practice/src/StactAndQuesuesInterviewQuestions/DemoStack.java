package StactAndQuesuesInterviewQuestions;

import java.util.EmptyStackException;

public class DemoStack implements IStackNode{
    int capacity;
    int size = 0;
    StackNode top;
    StackNode bottom;


    public DemoStack(int capacity) {
        this.capacity = capacity;
    }

    @Override
    public boolean isFull() {
        return capacity == size;
    }

    @Override
    public void join(StackNode newNode, StackNode oldBelow) {
        if(oldBelow != null) {
            oldBelow.above = newNode;
        }
        if(newNode != null){
            newNode.below = oldBelow;
        }
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public boolean push(int value) {
        if(size >= capacity)
            return false;
        size++;
        StackNode newNode = new StackNode(value);
        if(size == 1){
            top = bottom = newNode;
        }else{
            join(newNode,top);
            top = newNode;
        }
        return true;
    }

    @Override
    public int pop() {
        if(top == null) throw new EmptyStackException();
        int result = top.value;
        size--;
        top = top.below;
        return result;
    }

    @Override
    public int peek() {
        return top.value;
    }

    public int removeBottom(){
        StackNode remove = bottom;
        bottom = remove.above;
        if(bottom != null) bottom.below = null;
        size--;
        return remove.value;
    }
}
