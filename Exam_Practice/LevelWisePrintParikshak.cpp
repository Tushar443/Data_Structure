#include<iostream>
using namespace std;
class Node
{
    private:
            int data;
            Node* left;
            Node* right;
    public:
            Node()
            {
                data=0;
                left=right=NULL;
            }
            Node(int data)
            {
                this->data=data;
                left=right=NULL;
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
            void setRight(Node* right)
            {
                this->right=right;
            }
            void setLeft(Node* left)
            {
                this->left=left;
            }
};
class BST
{
    private:
            Node* root;
            int Queue[100],front,rear;
    public:
            BST()
            {
                root=NULL;
                front=rear=-1;
            }
            ~BST()
            {
                root=NULL;
            }
            void Insert(int data)
            {
                Node* node=new Node(data);
                if(root==NULL)
                {
                    root=node;
                }
                else
                {
                    Node* temp=root;
                    Node* prev=NULL;
                    while(temp!=NULL)
                    {
                        prev=temp;
                        if(data<=temp->getData())
                        {
                            temp=temp->getLeft();
                        }
                        else
                        {
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
            Node* getRoot()
            {
                return root;
            }
            int Height(Node* root)
            {
                int x;
                if(root==NULL)
                {
                    return 0;
                }
                x=max(Height(root->getLeft()),Height(root->getRight()))+1;
                return x;
            }
            void LevelOrder(Node* root)
            {
                int h=Height(root)+1;
                int i;
                for(i=1;i<h;i++)
                {
                    PrintLevel(root,i);
                    while(front!=rear)
                    { 
                        if(front==(rear-1))
                        {
                            cout<<Queue[++front]<<endl;
                            break;
                        }
                        cout<<Queue[++front]<<" ";
                    }
                        
                    if(front==rear)
                    {
                        front=rear=-1; 
                    }
                }
            }
            void PrintLevel(Node* root, int Level)
            {   
                if(root ==NULL)
                {
                    return;
                }
                if(Level==1)
                {
                    Queue[++rear]=root->getData();
                }
                else if(Level>1)
                {
                 PrintLevel(root->getLeft(),Level-1);
                 PrintLevel(root->getRight(),Level-1);
                }
            }
};

int main()
{
    BST b1;
    int n;

    while(1)
    {
         cin>>n;
        if(n!=(-1))
        {  
            b1.Insert(n);
        }
        else
            break;
    }
  cout<<b1.Height(b1.getRoot())<<endl;
  b1.LevelOrder(b1.getRoot());
    return 0;
}