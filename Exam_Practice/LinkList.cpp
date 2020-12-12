#include <iostream>
using namespace std;
class Node{
    private : 
        int data;
        Node* next;

    public :
        Node(int data)
        {
            this->data = data;
            next=NULL;;
        }
        Node(){
            next=NULL;
        }
        int getData(){
            return data;
        }
        Node* getNext(){
            return next;
        } 
        void setData(int data){
            this->data = data;
        }
        void setNext(Node* next){
            this->next=next;
        }
};
class LinkList
{
    
private:
    Node* root;
public:
    LinkList()
    {
        root=NULL;
    }
    ~LinkList()
    {
    }
    void InserData(int data){
        Node* node = new Node(data);
        if(root==NULL){
            root= node;
        }else{
                Node* temp = root;
                while (temp->getNext()!=NULL){
                    temp=temp->getNext();
                }
                temp->setNext(node);
        }
    }
    void InsertBefore(int data)
    {
        Node* node = new Node(data);
        Node* temp = root;
        if(root==NULL){
            root=node;
        }
        else
        {
            node->setNext(root);
            root=node;
        }
        

    }
    void Dispaly(){
        Node* temp = root;
        while (temp->getNext()!=NULL)
        {
            cout<<temp->getData()<<endl;
            temp=temp->getNext();
        }
         cout<<temp->getData()<<endl;
    }
};

int main()
{
    LinkList l;
    // l.InserData(12);
    // l.InserData(23);
    // l.InserData(45);
    l.InsertBefore(23);
    l.InsertBefore(56);
    l.InsertBefore(89);
    l.Dispaly();


    return 0;
}