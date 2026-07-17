package StactAndQuesuesInterviewQuestions.ThreeElevatorsProblem;

public class CircularQueue {
    int front;
    int rear;
    int[] store;
    int size;
    int noe;

    public CircularQueue(int size) {
        this.size = size;
        front = rear = -1;
        noe=0;
        store = new int[size];
    }

    public boolean isEmpty(){
        return noe == 0;
    }

    public boolean isFull(){
        return noe==size;
    }

    public int dequeue(){
        if(isEmpty()){
            return -1;
        }
        front= (front+1) % size;
        noe--;
        int data = store[front];
        if(front == rear){
            front = rear =-1;
        }
        return data;
    }

    public void enqueue(int val){
        if(isFull()){
            return;
        }else{
            rear = (rear +1)%size;
            noe++;
            store[rear] = val;
        }
    }

    public int getFront() {
        return front;
    }

    public int getRear() {
        return rear;
    }
}
