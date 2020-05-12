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
             Node()
             {}
             ~Node()
             {
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
class Tree
{
    private:
            Node* root;
    public:
            Tree()
            {
                root=NULL;
            }
            ~Tree()
            {
                root=NULL;
            }
            void Insert(int data)
            {
                Node* node=new Node(data);
                Node* temp=root;
                Node* prev=root;
                if(root==NULL)
                {
                    root=node;
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
                        prev->setLeft(node);
                    }
                    else
                    {
                        prev->setRight(node);
                    }
                }
            }
            void Search(int data)
            {
                Node* temp;
                temp=root;
                 if(temp->getData()==data)
                     cout<<"Root"<<endl;
              else
              {
                while(temp!=NULL && temp->getData()!=data)
                {
                    if(temp->getData()>data)
                    {
                        temp=temp->getLeft();
                    }
                    else
                    {
                        temp=temp->getRight();
                    }
                }
                
                if(temp==NULL)
                {
                    cout<<"Not Found"<<endl;
                }
                else
                {
                         cout<<"Root ";
                         temp=Find(root,data);
                         cout<<endl;
                
                }
              }
            }
            Node* Find(Node* root,int data)
            {
                if(root==NULL)
                {
                    return (NULL);
                }
                else
                {
                   Node* temp=root;
                    while(temp!=NULL && temp->getData()!=data)
                    {
                        if(temp->getData()>data)
                        {
                             cout<<"L"<<" ";
                             temp=temp->getLeft();
                        }
                        else
                        {
                            cout<<"R"<<" ";
                             temp=temp->getRight();
                        }
                     }
                }
            }
            
};
int main()
{
    Tree t;
    int N,a;
    while(1)
    {
        cin>>a;
        if(a!=(-1))
        {
            t.Insert(a);
        }
        else break;
    }
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
    t.Search(n);
    }
    return 0;
}