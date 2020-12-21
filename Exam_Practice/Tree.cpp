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
class  Tree
{
private:
    Node* root;
public:
    Tree()
    {
        root = NULL;
    }
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

};
int main()
{
    Tree t ;
    t.insertData(34);
    t.insertData(23);
    t.insertData(56);
    t.insertData(6);
    t.insertData(80);
    t.Print();
    
    return 0;
}