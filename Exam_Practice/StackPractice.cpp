#include<iostream>
using namespace std;

class Node{
    private :
        int data;
        Node* next;
        //For tree //Node* right;
        //Node* left;
    public:
        Node(){}
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        void setNext(Node* next){
            this->next=next;
        }
        Node* getNext(){
            return next;
        }
        int getData(){
            return data;
        }
};
class LinkList{
    Node* head;
    public :
        LinkList(){
            head=NULL;
        }
        void InsertData(int data){
            Node* node = new Node(data);
            if(head == NULL)
            {
                head=node;
            }
            else
            {
                Node* temp = head;
                while (temp->getNext()!=NULL)
                {
                   // prev =temp;
                    temp= temp->getNext();
                }
                temp->setNext(node);
                //prev->setNext(node);
            }
            
        }

        void Display(){
            Node* temp = head;
            while (temp->getNext()!=NULL)
            {
                cout<<temp->getData()<<"=>";
                temp=temp->getNext();
            }
            cout<<temp->getData();
            
        }


};
int main(){
    LinkList l ;
    l.InsertData(10);
    l.InsertData(20);
    l.InsertData(30);
    l.InsertData(40);
    l.Display();
    return 0;
}