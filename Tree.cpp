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
            int In[20];
            int Pre[20];
            int count;
            int p;
            int q;
    public:
            Tree()
            {
                count=0;
                p=q=0;
                root=NULL;
            }
            void Insert(int data)
            {
                count++;
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
            void Traversal()
            {
              //  cout<<" Inoreder"<<endl;
                Inprint(root);
             //   cout<<endl;
              //  cout<<"preOderder"<<endl;
                InprintP(root);
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
                  //  cout<<temp->getData()<<" ";

                    In[p++]=temp->getData();
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
                    //cout<<temp->getData()<<" ";
                    Pre[q++]=temp->getData();
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
            void PrintM()
            {
                for(int i=0;i<count;i++)
                {
                    if(In[i]==Pre[i])
                    {
                        cout<<i<<" "<<In[i]<<endl;
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
    t.PrintM();

    return 0;
}
