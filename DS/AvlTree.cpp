#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
    private:
            int data;
            Node* left;
            Node* right;
    public:
            Node(int data)
            {
                this->data=data;
                left=NULL;
                right=NULL;
            }
            int getData()
            {
                return data;
            }
            Node* getLeft()
            {
                return left;
            }
            Node* getRight()
            {
                return right;
            }
            void setLeft(Node* left)
            {
                this->left=left;
            }
            void setRight(Node* right)
            {
                this->right=right;
            }
};
class BST
{
    private:
            Node* root;
    public:
            BST()
            {
                root=NULL;
            }
            Node* getRoot()
            {
                return root;
            }
            int Height(Node* root)
            {
                if(root==NULL)
                    return 0;
                int x=max(Height(root->getLeft()),Height(root->getRight()))+1;
                return x;
            }
            void Insert(int data)
            {

                Node* node=new Node(data);
                Node* temp=root;
                Node* prev=root;
                if(root==NULL)
                {
                    root=node;
                   // cout<<"ROOT"<<" "<<node->getData()<<endl;
                }
                else
                    {
                        while(temp!=NULL)
                        {
                            if(data<=(temp->getData()))
                            {
                                prev=temp;
                                temp=temp->getLeft();
                            }
                            else
                            {
                                prev=temp;
                                temp=temp->getRight();
                            }
                        }
                        if(data<=prev->getData())
                        {
                           // cout<<"lEFT"<<" "<<node->getData()<<endl;
                            prev->setLeft(node);
                        }
                        else
                        {
                           // cout<<"RIGHT"<<" "<<node->getData()<<endl;
                            prev->setRight(node);
                        }
                    }
            }
            Node* RightRotation(Node* root)
            {
                Node* x=root->getLeft();
                Node* T=x->getRight();
                x->setRight(root);
                root->setLeft(T);
                return x;
            }
            Node* LeftRotation(Node* root)
            {
                Node* x=root->getRight();
                Node* T=x->getLeft();
                x->setLeft(root);
                root->setRight(T);
                return x;
            }
            Node* FindAVL(Node* root)
            {
                if(root!=NULL)
                {
                       int x=(Height(root->getLeft())-Height(root->getRight()));
                        if(x>1 || x<-1)
                            return root;
                        Node* node=FindAVL(root->getLeft());
                        if(node!=NULL)
                            return node;
                        node=FindAVL(root->getRight());
                        if(node!=NULL)
                            return node;
                }
                else
                    return NULL;
            }
            void Voilation()
            {
                Node* node=FindAVL(root);
                if(node==NULL)
                {
                    cout<<"NO voilation"<<endl;
                }
                else
                {
                    int Left=Height(node->getLeft());
                    int Right=Height(node->getRight());
                    if(Left>Right)
                    {
                        cout<<"Right Rotation required"<<endl;
                        Node* temp=FindParent(node->getData());
                        Node* newNode=RightRotation(node);
                        temp->setLeft(newNode);
                    }
                    else
                    {
                       cout<<"Left Rotation required"<<endl;
                        Node* temp=FindParent(node->getData());
                        Node* newNode=LeftRotation(node);
                        temp->setLeft(newNode);
                    }

                }
                Traversal();
            }
            Node* FindParent(int data)
            {
                cout<<"Find"<<endl;
                Node* temp=root;
                while(temp!=NULL)
                {
                   cout<<"while"<<endl;
                    if(temp->getLeft()!=NULL)
                    {
                        if(temp->getLeft()->getData()==data)
                            return temp;
                    }
                    if(temp->getRight()!=NULL)
                    {
                        if(temp->getRight()->getData()==data)
                            return temp;
                    }
                    if(temp->getData()<data)
                        temp=temp->getRight();
                    else
                        temp=temp->getLeft();
                }

            }
            void AVLvoilation()
            {
                int h=Height(root->getLeft())-Height(root->getRight());
                if(h>1 || h<-1)
                    cout<<"AVL voilation"<<endl;
                else
                    cout<<"NO Vio"<<endl;
            }
            void Traversal()
            {
                cout<<" Inoreder"<<endl;
                Inprint(root);
                cout<<endl;
            }
            int* Inprint(Node* temp)
            {
                if(temp!=NULL)
                {
                    if(temp->getLeft())
                       Inprint(temp->getLeft());
                   cout<<temp->getData()<<" ";
                    if(temp->getRight())
                       Inprint(temp->getRight());
                }
            }
};
int main(){
    BST bst;
    while(1){
        string cmd;
        cin>>cmd;
        if( cmd == "ex"){
            break;
        }else if( cmd == "in"){
            int data;
            cin>>data;
            bst.Insert(data);
            cout<<"insert root"<<endl;
         //   bst.Voilation();
        }else if( cmd == "DL"){
            int data;
            cin>>data;
          //  bst.deleteN( data );
        }else if( cmd == "BFT"){
           // bst.BFT();
           // bst.inorder();
        }else if( cmd == "H"){
            cout<<"Height: "<<bst.Height(bst.getRoot())<<endl;
        }
    }
    return 0;
}
