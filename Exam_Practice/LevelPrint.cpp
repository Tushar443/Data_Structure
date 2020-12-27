#include<iostream>
using namespace std;
class Node
{
    private :
    int data;
    Node* left;
    Node* right;
    public :
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
        Node(){
            this->data=0;
            this->left=NULL;
            this->right=NULL;
        }
        void setData(int data){
            this->data=data;
        }       
        int getData(){
            return data;
        }
        Node* getLeft(){
            return left;
        }
        void setLeft(Node* left)
        {
            this->left=left;
        }
        Node* getRight(){
            return this->right;
        }
        void setRight(Node* right){
            this->right=right;
        }
};
class Queue{
    private :
    int front;
    int rear;
    int size;
    int* store;
    public:
    Queue(int size){
        this->size=size;
        front=rear=-1;
        store=new int[size];
    }
    Queue(){
        size=20;
        front=rear=-1;
        store=new int[size];
    }
    void Enqueue(int data){
            store[++rear]=data;    
    }
    ~Queue(){delete[] store;}
    int Dequeue(){
            int data = store[++front];
            return data;
    }
    
    bool isEmpty(){
        if(front == rear){
            front = rear=-1;
            return true;
        }
        return false;
    }
    bool isFull(){
        if(rear == (size -1) ){
            return true;
        }
        return false;
    }
};
class  Tree
{
private:
    Node* root;
    int queue[20];
    int front,rear;
public:
    Tree()
    {
        root = NULL;
        front=rear=-1;
    }
    Node* getRoot(){return root;}
    void insertData(int data)
    {
       
        Node* node = new Node(data);
        Node* temp=root;
        Node* prev=root;
        if(root==NULL)
        {// cout<<"inside"<<endl;
            root=node;
        }
        else
        {
            while (temp!=NULL)
            {
               // cout<<"While loop "<<endl;
                if(temp->getData() >= data){
                    prev=temp;
                   temp = temp->getLeft();
                }
                else if(temp->getData() <= data)
                {
                    prev=temp;
                    temp=temp->getRight();
                }
            } //while loop end
            if(prev->getData() <= data){
                
               // cout<<"right"<<endl;
                prev->setRight(node);
            }
            else
            {
               // cout<<"left"<<endl;
                prev->setLeft(node);
            }   
        } //else
    } //function

    ~Tree()
    {
        root=NULL;
    }
    void Print(){
        ShowInorder(root);
    }
    void ShowInorder(Node* temp){
        if (temp!=NULL) 
        {
 
            if(temp->getLeft()!=NULL){
                ShowInorder(temp->getLeft());
            }
            cout << temp->getData() <<" ";
            if(temp->getRight()!=NULL){
                ShowInorder(temp->getRight());
            }

        }      
    }
 
 /*int Height(Node* root)
            {
                int x;
                if(root==NULL)
                {
                    return 0;
                }
                x=max(Height(root->getLeft()),Height(root->getRight()))+1;
                return x;
            }*/
    int Height(Node* root){
       int x;
        if(root==NULL){
            return 0;
        }
           x = max(Height(root->getLeft()),Height(root->getRight()))+1;
           return x; 
    }
    void PrintLevel(Node* root ,int level){
        if(root==NULL){
            return ;
        }
        else if(level==1){
            queue[++rear]=root->getData();
        }   
        else
        {
            PrintLevel(root->getLeft(),level-1);
            PrintLevel(root->getRight(),level-1);
        }
        
    }
    void LevelPrint(Node* root){
        int h = Height(root);
        for(int i=1;i<h;i++){
            PrintLevel(root,i);
            while (front!=rear)
            {
                if(front==(rear-1)){
                    cout<<queue[++front]<<endl;
                }
                cout<<queue[++front]<<" ";
            }
            if(front == rear){
                front=rear=-1;
            }
            
        }
    }
};



int main()
{
   
    Tree t ;
    t.insertData(5);
    t.insertData(10);
    t.insertData(20);
    t.insertData(11);
    t.insertData(12);
    t.insertData(14);
    t.insertData(15);
   cout<< t.Height(t.getRoot())<<endl; 
   t.LevelPrint(t.getRoot()); 
    return 0;
}