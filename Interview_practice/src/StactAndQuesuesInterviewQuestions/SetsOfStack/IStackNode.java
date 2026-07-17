package StactAndQuesuesInterviewQuestions.SetsOfStack;

public interface IStackNode {
     boolean isFull();

     boolean isEmpty();

     boolean push(int value);

     int pop();

     int peek();

     void join(StackNode before,StackNode after);
}
