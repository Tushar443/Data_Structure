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

        void InsertAfterData(int data, int after){
            Node* node = new Node(data);
            if(head == NULL){
                head= node;
            }
            else if(head->getData()==after){
                head->getNext()->setPrev(node);
               
                node->setNext(head->getNext());
                node->setPrev(head);
                head->setNext(node);
            }else{
                Node* temp = head;
                while(temp->getData()!=after){
                    temp=temp->getNext();
                }
                temp->getNext()->setPrev(node);
                node->setNext(temp->getNext());
                temp->setNext(node);
                node->setPrev(temp);

            }
        }
        
        void InsertBeforeData(int data, int before){
            Node* node = new Node(data);
            if(head==NULL){
                head=node;
            }
            else if(head->getData()==before)
            {
                head->setPrev(node);
                node->setNext(head);
                head= node;
            }else{
                Node* temp=head;
                while (temp->getData()!=before){
                    temp=temp->getNext();
                }
                
                node->setPrev(temp->getPrev());
                temp->setPrev(node);
                node->setNext(temp);
                node->getPrev()->setNext(node); 
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
     d.Insert(10);
     d.Insert(20);
     d.Insert(30);
     d.Insert(40);
     d.Insert(50);
     //d.InsertAfterData(25,20);
     //d.InsertAfterData(15,10);
     d.InsertBeforeData(15,20);
     d.InsertBeforeData(5,10);
     d.Display();
    //  d.InsertBefore(10);
    //  d.InsertBefore(20);
     
    //  d.InsertBefore(30);
    //  d.InsertBefore(40);
    //  d.InsertBefore(50);
     //d.Display();
    return 0;
}
