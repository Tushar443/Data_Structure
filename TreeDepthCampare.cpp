//compare Depth and Node of the tree
#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
    private:
        int data;
        node* left;
        node * right;
    public:
        node(int data)
        {
            this->data=data;
            left=NULL;
            right=NULL;
        }
        int getdata()
        {
            return data;
        }
        node * getleft()
        {
            return left;
        }
         node * getright()
        {
            return right;
        }
        void setright(node * right)
        {
            this->right=right;
        }
          void setleft(node * left)
        {
            this->left=left;
        }
        
        
};


class Tree
{
    private:
        node *root;
    public:
        Tree()
        {
            root=NULL;
        }
        node * getroot()
        {
            return this->root;
        }
        
        void insert(int data)
        {
            node * Node =new node(data);
            node * temp=root;
            node * prev=root;
            
            if(root==NULL)
            {
                root=Node;
            }
            else
            {
                while(temp!=NULL)
                {
                    prev=temp;
                    if(data<=temp->getdata())
                    {
                        temp=temp->getleft();
                    }
                    else
                    temp=temp->getright();
               }
                       if(data<=prev->getdata())
                    {
                        prev->setleft(Node);
                    }
                    else
                         prev->setright(Node);
                    
        }
}



int depth(node * temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        int left=depth(temp->getleft());
        int right=depth(temp->getright());
        
        if(left>right)
        return (left +1);
        else
        return (right +1);
    }
}
};

int campare(node * temp1 ,node * temp2)
{
  
    if(temp1==NULL && temp2==NULL)
    return 1;
    if(temp1!=NULL && temp2!=NULL)
    {
        int x=(campare(temp1->getleft(),temp2->getleft()) && campare(temp1->getright(),temp2->getright()));
        return x;
    }
    else 
    return 0;
}

int main()
{
    Tree t1;
    int n;
    cin>>n;
    int c=1;
 
    for(int i=0; i<n;i++)
    {
          Tree t2;
        if(i==0)
        {
            while(c!=-1)
            {
                cin>>c;
                if(c!=-1)
                {
                    t1.insert(c);
                }
            }
        }
      
        else
        {
            c=1;
         
            while(c!=-1)
            {
                  
                cin>>c;
                if(c!=-1)
                t2.insert(c);
            }
            int diff=(t2.depth(t2.getroot()))-(t1.depth(t1.getroot()));
            int j=campare(t1.getroot(),t2.getroot());
            if(j==1)
            {
                cout<<"YES"<<" "<<diff<<endl;
            }
            else if(j==0)
                cout<<"NO"<<" "<<diff<<endl;
            
        }
    }
    return 0;
}