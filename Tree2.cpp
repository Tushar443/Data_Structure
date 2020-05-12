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
            int c,p,q;
    public:
            Tree()
            {
                root=NULL;
                c=p=q=0;
            }
            ~Tree()
            {
                root=NULL;
            }
            void Insert(int data)
            {
                c++;
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
                            if((node->getData())<(temp->getData()))
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
                        if((node->getData())<(prev->getData()))
                        {
                            prev->setLeft(node);
                        }
                        else
                        {
                            prev->setRight(node);
                        }
                    }
            }
            void Traversal()
            {
                Inprint(root);
                InprintP(root);
            }
            int Inprint(Node* temp)
            {
                if(temp!=NULL)
                {
                    if(temp->getLeft()!=NULL)
                    {
                        Inprint(temp->getLeft());
                    }
                   In[p++]=temp->getData();
                    if(temp->getRight()!=NULL)
                    {
                        Inprint(temp->getRight());
                    }
                }
                else return 0;
                
            }
            int InprintP(Node* temp)
            {
                if(temp!=NULL)
                {
                    Pre[q++]=temp->getData();                
                    if(temp->getLeft() != NULL)
                    {
                        InprintP(temp->getLeft());
                    }
                    
                    if(temp->getRight() != NULL)
                    {
                        InprintP(temp->getRight());
                    }
                }
                else return 0;
                
            }
            void PrintM()
            {
                for(int i=0;i<c;i++)
                {
                    if(In[i]==Pre[i])
                    {
                        cout<<++i<<" "<<In[i]<<endl;
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
        else break;
    }
     
    t.Traversal();
     t.PrintM();
    return 0;
}