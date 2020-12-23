#include<iostream>
using namespace std;
class Queue{
    private :
        int data;
        int* store;
        int front;
        int rear;
        int n;
        int size;
    public:
        Queue(int size){
            data=0;
            store=new int[size];
            front=-1;
            rear = -1;
            n=0;
            this->size = size;
        }
        bool isFull(){
            if(n == size){
                return true;
            }
            return false;
        }
        bool isEmpty(){
            if(n == 0 || front ==rear)
            {
                return true;
            }
            if(front == rear){
                front =rear=-1;
            }
            return false;
        }
        void Enqueue(int data){
         
            if(isFull()){
                cout<<"Queue is Full"<<endl;
                return;
            }
            n++;
            store[++rear]= data;
            cout<<"Enqueue "<<data<<endl;
        }
        int Dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return 0;
            }
            n--;
            int data = store[++front];
            return data;
        }
};

int main(){
    Queue q(4);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    return 0;
}