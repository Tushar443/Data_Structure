package StactAndQuesuesInterviewQuestions.SetsOfStack;

import java.util.ArrayList;

public class SetOfStack {

    public int capacity;
    ArrayList<DemoStack> stacks = new ArrayList<>();

    public SetOfStack(int capacity) {
        this.capacity = capacity;
    }

    public DemoStack getLastStack(){
        if(stacks.isEmpty()){
            return null;
        }else{
            return stacks.get(stacks.size()-1);
        }
    }

    public void push(int value){
        DemoStack last = getLastStack();
        if(last== null){
            DemoStack newStack = new DemoStack(capacity);
            newStack.push(value);
            stacks.add(newStack);
        }
        if(last != null && last.isFull()){
           DemoStack newStack = new DemoStack(capacity);
           newStack.push(value);
           stacks.add(newStack);
        }else if (last != null){
            last.push(value);
        }
    }

    public int pop(){
        DemoStack last = getLastStack();
        int result = 0 ;
        if(last != null){
            result = last.pop();
        }
        if(last != null && last.size == 0){
            stacks.remove(last);
        }
        return result;
    }

    public int leftShift(int index , boolean removeTop){
        DemoStack indexStack = stacks.get(index);
        int result;
        if(indexStack != null && removeTop){
            result = indexStack.pop();
        }else{
            result = indexStack.removeBottom();
        }
        if(indexStack.size == 0){
            stacks.remove(indexStack);
        } else if (stacks.size() > index + 1) {
            int value = leftShift(index + 1,false);
            indexStack.push(value);
        }
        return result;
    }

    public int popAt(int index){
        return leftShift(index,true);
    }

    public static void main(){
        SetOfStack stack = new SetOfStack(3);

        stack.push(1);
        stack.push(2);
        stack.push(3);

        stack.push(4);
        stack.push(5);
        stack.push(6);

        stack.push(7);
        stack.push(8);
        stack.push(9);

        stack.push(10);
        stack.push(11);
        stack.push(12);
        System.out.println(stack.popAt(2));
        System.out.println(stack.popAt(2));


    }
}
