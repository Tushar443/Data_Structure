#include<iostream>
using namespace std;
static int s=10;


class stack{
private :
        int size;
        int top;
        int* store;
public :
    stack(int size){
        this->size=size;
        top=-1;
        store= new int[size];
    }
    ~stack(){
        delete[] store;
    }
    void push(int data)
    {
        if(isFull())
        {
            cout<<"Stack is Full"<<endl;
            return;
        }
        store[++top]=data;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        int data =store[top--];
        return data;
    }
    bool isEmpty()
    {
        if(top==-1){
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if(top ==size)
        {
            return true;
        }
        return false;
    }
};

int main(){


int s;
cin>> s;
stack s1(s);

s1.push(34);
s1.push(45);
cout<<s1.pop()<<endl;
cout<<s1.pop()<<endl;
cout<<s1.pop()<<endl;
cout<<s1.pop()<<endl;

return 0;
}
