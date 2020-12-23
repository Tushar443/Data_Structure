#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node(){
        data=0;
        next=NULL;
    }
   
    void setNext(Node *next)
    {
        this->next = next;
    }
    Node *getNext()
    {
        return next;
    }
    int getData()
    {
        return data;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
    void push(int data)
    {
        Node *node = new Node(data);

        Node *temp = top;
        if (top == NULL)
        {
            top = node;
        }
        else
        {

            node->setNext(top);
            top = node;
            cout << "Push " << data << endl;
        }
    }
    Node* pop()
    {
        Node* temp = new Node();

        if (isEmpty())
        {
            cout << "Stackt is Empty" << endl;
             cout<<"End if"<<endl;
            return temp;
        }

        else
        {

            temp = top;
            top = top->getNext();
            cout << "pop " << temp->getData() << endl;
        }
    cout<<"End pop"<<endl;
        return temp;
    }
};

int main()
{
    Stack s;
    s.pop();
    s.push(23);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << s.pop()->getData() << endl;
    cout << s.pop()->getData() << endl;
    cout << s.pop()->getData() << endl;
    cout << s.pop()->getData() << endl;
    cout << s.pop()->getData() << endl;
    cout << s.pop()->getData() << endl;
    cout << s.pop()->getData() << endl;
    cout << s.pop()->getData() << endl;
    cout << s.pop()->getData() << endl;
    return 0;
}