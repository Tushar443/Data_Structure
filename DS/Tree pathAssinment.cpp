//Tree Path 

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
class Tree
{
    private:
            Node* root;
    public:
            Tree()
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
                        if(data<(temp->getData()))
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
                    if(data<prev->getData())
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
                cout<<data<<"=>"<<"Root"<<" ";
                temp=Find(root,data);
                cout<<"temp Data:-"<<temp->getData()<<endl;
                if(temp->getData()!=data)
                {
                    system("CLS");
                    cout<<data<<"=>"<<"Not Found"<<endl;
                }
            }
            Node* Find(Node* root,int data)
            {
                if(root==NULL)
                {
                    return (NULL);
                }
                else if(data<root->getData())
                {
                    cout<<"L"<<" ";
                    Find(root->getLeft(),data);
                }
                else if(data>root->getData())
                {
                    cout<<"R"<<" ";
                    Find(root->getRight(),data);
                }
                return root;
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
    cout<<"Enter the No of elment search"<<endl;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int n;
        cout<<"Enter the no to be search"<<endl;
        cin>>n;
        t.Search(n);
    }
    return 0;
}
