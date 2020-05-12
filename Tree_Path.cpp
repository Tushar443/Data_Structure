#include<iostream>
using namespace std;
class stack
{
private:
        int size;
        int top;
        int* store;
public:
    stack(int size)
    {
        this->size=size;
        store=new int [size];
        top=-1;
    }
    ~stack()
    {
        delete store;
    }
    int isEmpty()
    {
        if(top==-1)
            return 1;
        return 0;
    }
    int isFull()
    {
        if(top==(size-1))
            return 1;
        return 0;
    }
    void Push(int data)
    {
        store[++top]=data;
    }
    int Pop()
    {
        return store[top--];
    }

};
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
            void Traversal()
            {
              //  int arr1[10];
              //  int i=1;
              //  int *p,*q;
                cout<<" Inoreder"<<endl;
             Inprint(root);
                cout<<endl;
                cout<<"preOderder"<<endl;
             InprintP(root);

            }
            int Inprint(Node* temp)
            {
                    stack In(10);
                if(temp!=NULL)
                {
                    if(temp->getLeft())
                    {
                        Inprint(temp->getLeft());
                    }
                   // cout<<temp->getData()<<" ";
                        In.Push(temp->getData());
                       // cout<<"POP  "<<In.Pop()<<endl;

                    if(temp->getRight())
                    {
                        Inprint(temp->getRight());
                    }
                }
                    return 0;

            }
            int InprintP(Node* temp)
            {
                stack Pre(10);
                if(temp!=NULL)
                {
                    cout<<temp->getData()<<" ";
                    Pre.Push(temp->getData());
                    if(temp->getLeft()!=NULL)
                    {
                        InprintP(temp->getLeft());
                    }
                    if(temp->getRight()!=NULL)
                    {
                         InprintP(temp->getRight());
                    }
                }
                else
                    return 0;
            }
            void Print()
            {
                cout<<t.Pop()<<endl;
            }
};
int main()
{
    Tree t;
    int c=0,N;
     t.Insert(6);
      t.Insert(8);
       t.Insert(9);
        t.Insert(3);
         t.Insert(5);
          t.Insert(1);
           t.Insert(4);
            t.Traversal();
  /*  while(1)
    {
        cin>>N;
        if(N!=(-1))
        {
            c++;
            t.Insert(N);
        }
        else
            break;
    }
*/

 //  cout<<"same position"<<endl;
   // t.Print();

    return 0;
}
