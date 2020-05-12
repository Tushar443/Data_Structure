#include<iostream>
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
            int Queue[20];
            int Front;
            int rear;
    public:
            Tree()
            {
                Queue[20]=0;
                Front=rear=-1;
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
            int Height(Node* root)
            {
                if(root==NULL)
                {
                    return 0;
                }
                int x=max(Height(root->getLeft()),Height(root->getRight()))+1;
                    return x;
            }
            void BFT()
            {
             int h=Height(root);
                for(int i=1;i<=h;i++)
                {
                    PrintLevel(root,i);
                    while(Front!=rear)
                    {
                        if(Front==rear-1)
                        {
                            cout<<Queue[++Front]<<endl;
                            break;
                        }
                        cout<<Queue[++Front]<<" ";
                    }
                    if(Front==rear)
                    {
                        Front=rear=-1;
                    }

                }

            }
            void PrintLevel(Node* root, int level)
            {
                if(root==NULL)
                    return;
                else if(level==1)
                {
                    Queue[++rear]=root->getData();
                }
                else if(level>1)
                    PrintLevel(root->getLeft(),level-1);
                    PrintLevel(root->getRight(),level-1);
            }
            void Traversal()
            {
                cout<<" Inoreder"<<endl;
                Inprint(root);
                cout<<endl;
                cout<<"preOderder"<<endl;
                InprintP(root);
                cout<<endl;
            }
            int* Inprint(Node* temp)
            {
               // cout<<"adress of arr  "<<arr<<endl;
                if(temp!=NULL)
                {
                    if(temp->getLeft())
                    {
                       Inprint(temp->getLeft());
                    }
                   cout<<temp->getData()<<" ";

             //       In[p++]=temp->getData();
                  //   cout<<arr[--index]<<"  ";

                    if(temp->getRight())
                    {
                       Inprint(temp->getRight());
                    }
                }
            }
            int* InprintP(Node* temp)
            {
                if(temp!=NULL)
                {
                    cout<<temp->getData()<<" ";
                    //Pre[q++]=temp->getData();
                   // cout<<arr[--index]<<"  ";
                    if(temp->getLeft()!=NULL)
                    {
                        InprintP(temp->getLeft());
                    }
                    if(temp->getRight()!=NULL)
                    {
                         InprintP(temp->getRight());
                    }
                }
            }
};
int main()
{
    Tree t;
    int N;
    while(1)
    {
        cin>>N;
        if(N!=(-1))
        {
            t.Insert(N);
        }
        else
            break;
    }

    t.Traversal();
    cout<<"BFT"<<endl;
    t.BFT();
    //t.PrintM();

    return 0;
}
