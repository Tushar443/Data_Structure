#include<iostream>
using namespace std;
class Node {
    private : 
        int data;
        Node* left;
        Node* right;
    public :
        Node(){
            data=0;
            left=right=NULL;
        }
        Node(int data){
            this->data =data;
            left=right=NULL;
        }
        ~Node(){
            data = 0;
            left=right=NULL;
        }
        int getData(){
            
            return data;
        }
        void setData(int data){
            this->data=data;
        }
        Node* getLeft(){
            return left;
        }
        void setLeft(Node* left){
            this->left=left;
        }
        Node* getRight(){
            return right;
        }
        void setRight(Node* right){
            this->right = right;
        }
};

class BST{
    private :
        Node* root;
         int count;
        int arr[20];
        int i;
    public:
        BST(){
            root=NULL;
            count = 0;
            i=0;
        }
        ~BST(){
            root =NULL;
        }
        void InsertNode(int data){
            
            Node* node = new Node(data);
            if(root==NULL){
                
                root = node;
            }
            else
            {
                Node* temp = root;
                Node* prev = root;
                while(temp!=NULL){
                    if( temp->getData()>=data){

                        prev=temp;
                        temp=temp->getLeft();
                    }else
                    if(temp->getData()<=data){
                        prev=temp;
                        temp = temp->getRight();
                    }
                }
                if( prev->getData() <=data){
                    
                    prev->setRight(node);
                }
                else
                {
                   
                    prev->setLeft(node);
                }
                
            }
            
        }
        void SecondMinimum(Node* root){
            if(root!=NULL){
                SecondMinimum(root->getLeft());
                arr[i++] =root->getData();
                SecondMinimum(root->getRight());
            }
        }
        int FindMax(Node* root){
            SecondMinimum(root);
            return arr[count -1];
        }
        int SecondMinValueIs(){
            SecondMinimum(root);
            int temp = arr[1];
            return temp;
        }
        Node* getRoot(){
            return root;
        }
        int CountTotalNoOfNodes(Node* root){
           if(root!=NULL){
                count++;
                CountTotalNoOfNodes(root->getLeft());
                CountTotalNoOfNodes(root->getRight());
            }
            return count;
        }
        void PrintPreOrder(){
            Preorder(root);
        }
        void Preorder(Node* root){
            if(root!=NULL){
                  cout<<root->getData()<<" ";
                Preorder(root->getLeft());
               //cout<<root->getData()<<" ";
                Preorder(root->getRight());
            }
            
        }

        Node* DeleteNode(Node* root,int data){
            int temp ;
             Node* temp1;
            if(root==NULL){
                cout<<"No Data In Tree"<<endl;
            }
            else if(data<root->getData()){
                root->setLeft(DeleteNode(root->getLeft(),data));
            }else if(data> root->getData()){
                root->setRight(DeleteNode(root->getRight(),data));
            }else if(root->getLeft()!=NULL && root->getRight()!=NULL){
                temp=FindMax(root->getLeft());
                // cout<<temp<<endl;
                root->setData(temp);
                root->setLeft(DeleteNode(root->getLeft(),root->getData()));
            }else{
                temp1 = root;
                if(root->getLeft() ==NULL){
                    root =root->getRight();
        
                }
                if(root->getRight()==NULL){
                    root =root->getLeft();
                   

                }
                delete temp1;
                cout<<"Deleted"<<endl;;
            }
            
            return temp1;
        }
        

};

int main(){
    BST b;
    b.InsertNode(8);
    b.InsertNode(10);
    b.InsertNode(3);
    b.InsertNode(1);
    b.InsertNode(6);
    b.InsertNode(14);
    b.InsertNode(4);
    b.InsertNode(7);
    b.InsertNode(13);

    b.PrintPreOrder();
    cout<<endl;
    cout<<b.CountTotalNoOfNodes(b.getRoot())<<endl;
   cout<<b.SecondMinValueIs()<<endl;

    b.DeleteNode(b.getRoot(),10);
     b.PrintPreOrder();
    cout<<endl;
    return 0;
}