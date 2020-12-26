#include<iostream>
using namespace std;
class Queue{

private :
    int front;
    int rear;
    int* store;
    int size;

public :
    Queue(int size)
    {
        this->size=size;
        store = new int[size];
        front = -1;
        rear= -1;
    }
    void enqueue(int data){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
        }
        else
        {
            store[++front]=data;      
        } 
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            front=rear=-1;
            return 0;
        }
        else
        {
             int data =store[++rear];
             return data;    
        } 
    }
    bool isFull(){
        if(front ==size-1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        return false;
    }
};
int main()
{
    Queue q(3);
    q.enqueue(34);
    q.enqueue(45);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;


    return 0;
}
