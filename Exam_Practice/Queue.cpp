#include<iostream>
using namespace std;
class Queue{

private :
    int front;
    int rare;
    int* store;
    int size;

public :
    Queue(int size)
    {
        this->size=size;
        store = new int[size];
        front = -1;
        rare= -1;
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
            front=rare=-1;
            return 0;
        }
        else
        {
             int data =store[++rare];
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
        if(front == rare){
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
