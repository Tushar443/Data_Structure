#include<iostream>
using namespace std;
class Node
{
    private:
            int data;
            Node* next;
    public:
            Node(int data)
            {
                this->data=data;
                next=NULL;
            }
            int getData()
            {
                return data;
            }
            Node* getNext()
            {
                return next;
            }
            void setNext(Node* next)
            {
                this->next=next;
            }
            
};
class LinkList
{
    private:
            Node* head;
    public:
            LinkList()
            {
                head=NULL;
            }
            ~LinkList()
            {
                while(head!=NULL)
                {
                    Node* temp=head;
                    head=head->getNext();
                    delete temp;
                }
            }
            Node* getHead()
            {
                return head;
            }
            void InsertE(int data)
            {
                Node* node=new Node(data);
                if(head==NULL)
                    head=node;
                else
                {
                    Node* temp=head;
                    while(temp->getNext()!=NULL)
                    {
                        temp=temp->getNext();
                    }
                    temp->setNext(node);
                }
            }
            void InsertB(int data)
            {
                Node* node=new Node(data);
                if(head==NULL)
                    head=node;
                else
                {   
                    node->setNext(head);
                    head=node;
                }
            }
            int InsertAfter(int tobe,int After)
            {
                Node* node=new Node(tobe);
                Node* temp=head;
                while(temp!=NULL && temp->getData()!=After)
                {
                    temp=temp->getNext();
                }
                    if(temp==NULL)
                        return 0;
                    else
                        {
                            node->setNext(temp->getNext());
                            temp->setNext(node);
                        }
            }
            void InsertBefore(int tobe,int Before)
            {
                Node* node=new Node (tobe);
                Node* temp=head;
                if(head->getData()==Before)
                {
                    node->setNext(head);
                    head=node;
                }
                else
                {
                    while(temp!=NULL && temp->getNext()->getData()!=Before)
                    {
                        temp=temp->getNext();
                    }
                            node->setNext(temp->getNext());
                            temp->setNext(node);
                }
            }
            int DeleteAfter(int After)
            {
                Node* temp;
                temp=head;
                if(head==NULL)
                {
                    return 0;
                }
                else
                {
                    while(temp!=NULL && temp->getData()!=After)
                    {
                        temp=temp->getNext();
                        if(temp->getNext()==NULL)
                    {
                        return 0 ;
                    }
                    }
                    temp->setNext(temp->getNext()->getNext());
                }
            }
            int DeleteBefore(int Before)
            {
                
                Node* temp;
                Node* prev=head;
                temp=head;
               if(head!=NULL)
               {
                   if(head->getData()==Before)
                    return 0;
                    else
                        {
                            if(head->getNext()->getData()==Before)
                            {
                            head=head->getNext();
                            }
                        else
                            {
                                while(temp->getNext()->getData()!=Before)
                                {
                                     prev=temp;
                                    temp=temp->getNext();
                                }
                            if(temp==NULL)
                                return 0;
                            else
                                {
                                    if(prev->getData()==head->getData())
                                    {   
                                        head=temp;
                                        delete prev;
                                    }
                                    else
                                    prev->setNext(temp->getNext());
                                }
                            }
                        }
                }    
            }
            int DeleteNode(int data)
            {
                if(head->getData()!=data)
                {
                    Node* temp=head;
                    while(temp!=NULL && temp->getNext()->getData()!=data)
                    {
                        temp=temp->getNext();
                    }
                    temp->setNext(temp->getNext()->getNext());
                }
                else
                    {
                        head=head->getNext();
                    }
            }
            void Print()
            {
                Node* temp=head;
                while(temp!=NULL)
                {
                    cout<<temp->getData()<<" ";
                    temp=temp->getNext();
                    
                }
                 cout<<endl;
                    
                    
                
            }
            void FPrint()
            {
                cout<<endl;
                Node* temp=head;
                while(temp->getNext()!=NULL)
                {
                    cout<<temp->getData()<<"->";
                    temp=temp->getNext();
                }
                cout<<temp->getData()<<endl;
            }
            void RPrint(Node* temp)
            {   
                if(temp==NULL)
                    return ;
                RPrint(temp->getNext());
                cout<<temp->getData()<<" ";
                
            }
};
int main()
{
    LinkList l;
    Node* temp;
    string cmd;
    int data;
    while(1)
    {
        cin>>cmd;
        if(cmd=="AB")
        {
            cin>>data;
            l.InsertB(data);
        }
        if(cmd=="PR")
        {
            l.Print();
        }
        if(cmd=="AE")
        {
            cin>>data;
            l.InsertE(data);
        }
        if(cmd=="AMA")
        {
            int tobe,After;
            cin>>After>>tobe;
           l.InsertAfter(tobe,After); 
        }
        if(cmd=="AMB")
        {
            int tobe,Before;
            cin>>Before>>tobe;
           l.InsertBefore(tobe,Before);
        }
        if(cmd=="DN")
        {
            cin>>data;
            l.DeleteNode(data);
        }
        if(cmd=="DNA")
        {
            cin>>data;
            l.DeleteAfter(data);
        }
        if(cmd=="DNB")
        {
            cin>>data;
            l.DeleteBefore(data);
        }
         if(cmd=="FPR")
        {
           l.FPrint();
        }
        if(cmd=="RPR")
        {
            l.RPrint(l.getHead());
        }
        if(cmd=="EXIT")
        {
            break;
        }
        
    }
    return 0;
}