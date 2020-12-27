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
public:
    Tree()
    {
        root = NULL;
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
    void LevelOrder(){
       
        Queue q(10);
        
        Node* temp=root;
        if(temp!=NULL){ 
            q.Enqueue(temp->getData());
            while (!q.isEmpty())
            {
                int data = q.Dequeue();
                cout<<data<<endl;
              if(temp->getLeft()!=NULL){
                q.Enqueue(temp->getLeft()->getData());
                temp=temp->getLeft();
              }
                if(temp->getRight()!=NULL){
                q.Enqueue(temp->getRight()->getData());
                temp=temp->getRight();
                }
            }
            
        }

    }
    void Search(int data){
        //Find(root,data);
        FindPath(root,data);
    }
    void Find (Node* root , int data){
       if(root==NULL){
           cout<<"Not found"<<endl;
       }else
       {
            if(data < root->getData()){
                return Find(root->getLeft(),data);
            }
            if(data > root->getData()){
                return Find(root->getRight(),data);
            }
            else
            {
                cout<<"Found"<<endl;
            }
            
       }
       
        
    }
      void FindPath (Node* root , int data){
       if(root==NULL){
           cout<<"Not found"<<endl;
       }else
       {
           cout<<"Root "<<endl;

            if(data < root->getData()){
                Find(root->getLeft(),data);
           cout<<"L "<<endl;
                
            }
            if(data > root->getData()){
                Find(root->getRight(),data);
           cout<<"R "<<endl;
            }
            else
            {
                cout<<"Found"<<endl;
            }   
       }
    }
Node FindMax(Node* root){
   Node temp;
   Node RTemp,LTemp;
   int max = root->getData();
   if(root==NULL){
       return INT_MIN ;
   }
   else if(root->getLeft()!=NULL){
       LTemp = FindMax(root->getLeft());
   }
   else if(root->getRight()!=NULL){
       RTemp= FindMax(root->getRight());
   }
   if(LTemp.getData() > RTemp.getData()){
         temp= LTemp;
   }
   else
   {
       temp=RTemp;
   }
   return temp;
}
    Node* DeleteNode(Node* root,int data){
        Node temp;
        if(root == NULL){
            cout<<"No Data Exist"<<endl;
        }
        else if(data<root->getData()){
            root->setLeft(DeleteNode(root->getLeft(),data));
        }
        else if(data > root->getData()){
            root->setRight(DeleteNode(root->getRight(),data));
        }
        else if(root->getLeft()!=NULL && root->getRight()!=NULL){
            temp= FindMax(root->getLeft());
            root->setData(temp.getData());
            root->setLeft(DeleteNode(root->getLeft(),root->getData()));
        }
        else{
            Node* temp =root;
            if(root->getLeft() == NULL){
                root->getRight();
            }
            if(root->getRight() == NULL){
                root = root->getLeft();
            }
            delete temp;
        }
        return new Node();
    }
};



int main()
{
   
    Tree t ;
    // t.insertData(34);
    // t.insertData(23);
    // t.insertData(56);
    // t.insertData(6);
    // t.insertData(80);
    t.insertData(4);
    t.insertData(2);
    t.insertData(8);
    t.insertData(1);
    t.insertData(5);
    t.insertData(9);
    t.insertData(7);
    t.insertData(6);
    

    t.DeleteNode(t.getRoot(),5);
     t.Print();
   // t.LevelOrder();

    //t.Search(12);
    
    
    
    
     
     

     
     
    return 0;
}