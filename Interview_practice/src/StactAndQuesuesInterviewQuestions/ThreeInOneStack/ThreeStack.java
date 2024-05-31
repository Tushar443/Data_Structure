package StactAndQuesuesInterviewQuestions.ThreeInOneStack;

public interface ThreeStack {
     boolean isFull(int stackNum);

     boolean isEmpty(int stackNum);

     int topOfStack(int stackNum);

     void push(int stackNum,int value);

     int pop(int stackNum);

     int peek(int stackNum);
}
