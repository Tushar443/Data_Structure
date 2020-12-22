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
            next=NULL;
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
        cout<<"Inserted"<<endl;
        Node* node = new Node(data);
        if(root==NULL){
            root= node;
        }else{
                Node* temp = root;
                while (temp->getNext()!=NULL){
                    cout<<"inside while"<<endl;
                    temp=temp->getNext();
                }
                    cout<<"end while"<<endl;
                temp->setNext(node);
                cout<<"End of FUnc"<<endl;
        }
    }
    void InsertBefore(int data)
    {
                    cout<<"insert before root"<<endl;
        Node* node = new Node(data);
        Node* temp = root;
        if(root==NULL){
            root=node;
        }
        else
        {
                    cout<<"insert ELse"<<endl;
            node->setNext(root);
            root=node;
        }
    }
    void insertAfterData(int newData,int oldData){
        Node* node = new Node(newData);\
        Node* temp = root;
        if(root==NULL){
            root=node;
        }else{
            cout<<"Code" <<endl;
            while (temp->getData()!=oldData || temp->getNext()!=NULL)
            {
                cout<<"Inside While"<<endl;
                temp=temp->getNext();
            }
             cout<<"end While"<<endl;
            
            node->setNext(temp->getNext());
            temp->setNext(node);
            
        }

    }    

void insertBeforeData(int newData,int AfterData){
    Node* node = new Node(newData);
    Node* temp = root;
    if(root==NULL){
        root=node;
    }
    else
    {
        while (temp->getNext()->getData()!=AfterData || temp->getNext()!=NULL ||temp != NULL){
                    cout<<"inside while"<<endl;

            temp=temp->getNext();
        }
                    cout<<"end while"<<endl;

            node->setNext(temp->getNext());
            temp->setNext(node);
    }  
}
    
    void Dispaly(){
        Node* temp = root;
        while (temp!=NULL)
        {
            cout<<temp->getData()<<"=>"<<endl;
            temp=temp->getNext();
        }
         //cout<<temp->getData()<<endl;
    }
};

int main()
{
    LinkList l;
    l.InserData(12);
    l.InserData(23);
    l.InserData(45);
    l.InsertBefore(232);
    l.insertAfterData(100,232);
    l.InsertBefore(56);
    l.InsertBefore(89);
    //l.insertBeforeData(200,23); //error segmentation fault
    l.Dispaly();


    return 0;
}