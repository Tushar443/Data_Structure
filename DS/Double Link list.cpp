#include<iostream>
using namespace std;
class Node
{
private:
    int data;
    Node* next;
    Node* prev;
public:
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
    ~Node()
    {
        next=NULL;
        prev=NULL;
    }
    int getData()
    {
        return data;
    }
    Node* getNext()
    {
        return next;
    }
    Node* getPrev()
    {
        return prev;
    }
    void setNext(Node* next)
    {
        this->next=next;
    }
    void setPrev(Node* prev)
    {
        this->prev=prev;
    }
};
class DlinkList
{
private:
    Node* head;
public:
    DlinkList()
    {
        head=NULL;

    }
    ~DlinkList()
    {
        head=NULL;

    }
    void InsertB(int data)
    {
        Node* node=new Node(data);
        if(head==NULL)
        {
            head=node;
        }
        else
        {
          Node* temp=head;
          node->setNext(head);
          head=node;
          temp->setPrev(head);
        }

    }
    int print()
    {
        if(head!=NULL)
        {
            Node* temp=head;
            while(temp!=NULL)
            {
                cout<<temp->getData()<<endl;
                    temp=temp->getNext();
            }
        }
        else return 0;
    }
    int printP()
    {
        if(head!=NULL)
        {
            Node* temp=head;
            while(temp->getNext()!=NULL)
            {
                    temp=temp->getNext();
            }
            while(temp!=NULL)
            {
                cout<<temp->getData()<<endl;
                temp=temp->getPrev();
            }
        }
        else return 0;
    }
    void InsertE(int data)
    {
        Node* node=new Node(data);
        if(head==NULL)
            head=node;
        else
        {
            Node* temp=head;
            while(temp->getNext()!=NULL)
            {
                    temp=temp->getNext();
            }
            temp->setNext(node);
            node->setPrev(temp);
        }
    }
    void InsertAfter(int tobe,int After)
    {
        Node* node=new Node(tobe);

        if(head!=NULL)
        {
            Node* temp=head;
            while((temp->getData())!=After)
            {
                temp=temp->getNext();
            }
            node->setNext(temp->getNext());
            temp->setNext(node);
            temp->getNext()->setPrev(node);
            node->setPrev(temp);
        }

    }
    void InsertBefore(int tobe,int Before)
    {
        if(head!=NULL)
        {
            Node* node=new Node(tobe);
            Node* temp=head;
            while(temp->getData()!=Before)
            {
                temp=temp->getNext();
            }
            node->setNext(temp);
            temp->getPrev()->setNext(node);
            node->setPrev(temp->getPrev());
            temp->setPrev(node);
        }
    }
    int DeleteE()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            temp=temp->getNext();
        }
        delete temp;
    }
};
int main()
{
    DlinkList d;
    d.InsertE(11);
    d.InsertE(12);
    d.InsertE(13);
    d.InsertE(14);
    d.InsertE(15);
    d.InsertE(16);
    d.InsertE(17);
    //d.InsertB(17);
    //d.InsertB(18);
    //d.InsertAfter(6,16);

    d.DeleteE();

    d.print();

  //  d.printP();
    return 0;
}
