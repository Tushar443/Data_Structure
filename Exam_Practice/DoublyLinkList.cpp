#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node* prev;

    public :
        Node(){}
        Node(int data){
            this->data=data;
            next=prev=NULL;
        } 
        Node* getNext(){
            return next;
        }
        Node* getPrev(){
            return prev;
        }
        void setNext(Node* next){
            this->next=next;
        }
        void setPrev(Node* prev){
            this->prev=prev;
        }
        int getData(){
            return data;
        }
};

class DoublyLink{
    private :
        Node* head;
    public:
        DoublyLink(){
            head=NULL;
        }
        void Insert(int data){
            Node* node = new Node(data);
            if(head==NULL){
                head=node;
            }else{
                Node* temp = head;
                while (temp->getNext()!=NULL)
                {
                    temp=temp->getNext();
                }
                temp->setNext(node);
                node->setPrev(temp);
            }
        }
        void InsertBefore(int data){
             Node* node = new Node(data);
            if(head==NULL){
                head=node;
            }else{
                Node* temp = head;
               node->setNext(temp);
                temp->setPrev(node);
                head= node;
            }
        }

        void Display(){
            Node* temp = head;
            while (temp->getNext()!=NULL)
            {
                cout<<temp->getData()<<" ";
                temp=temp->getNext();
            }
            cout<<temp->getData()<<endl;
            cout<<endl;
            cout<<"@@@@@@@@@@@@@@@@@@@@@"<<endl;
            while (temp->getPrev()!=NULL)
            {
                cout<<temp->getData()<<" ";
                temp=temp->getPrev();
            }
            cout<<temp->getData()<<endl;
        }
};

int main(){

    DoublyLink d ;
    //  d.Insert(10);
    //  d.Insert(20);
    //  d.Insert(30);
    //  d.Insert(40);
    //  d.Insert(50);
    //  d.Display();
     d.InsertBefore(10);
     d.InsertBefore(20);
     d.InsertBefore(30);
     d.InsertBefore(40);
     d.InsertBefore(50);
     d.Display();
    return 0;
}
