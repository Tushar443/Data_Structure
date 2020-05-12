#include<iostream>
#include<stdlib.h>
using namespace std;
class Queue
{
     private:
		int front,rear;
		int* store;
		int size;
     public:
            Queue(int size)
            {
                this->size=size;
                front=rear=-1;
                store=new int[size];
            }
            int isEmpty()
            {
                if(front==rear)
                    return 1;
                return 0;
            }
            int isFull()
            {
                if(rear==(size-1))
                    return 1;
                return 0;
            }
            void Enque(int s)
            {
                store[++rear]=s;
            }
            int Deque()
            {
                char s=store[++front];
                return s;
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
            void Serach(int data)
            {
                Queue  s(10);
                Node* temp;
                //cout<<data<<"=>"<<"Root"<<" ";
                temp=Find(root,data,s);

               // cout<<"temp Data:-"<<temp->getData()<<endl;
                if(temp==NULL)
                {
                    cout<<data<<"=>"<<"Data Not Found"<<endl;
                }
                else
                {
                    cout<<data<<"=>";
                    while(!s.isEmpty())
                    {
                        cout<<char(s.Deque())<<" ";
                    }
                }
            }
            Node* Find(Node* root,int data,Queue s)
            {

                if(root==NULL)
                    return (NULL);
                else if(data<root->getData())
                {
                    //cout<<"L"<<" ";
                    s.Enque(int("L"));
                    Find(root->getLeft(),data,s);

                }
                else if(data>root->getData())
                {
                    //cout<<"R"<<" ";
                    s.Enque(int("R"));
                    Find(root->getRight(),data,s);

                }
                else
                    return root;

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
           t.Serach(5);
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
