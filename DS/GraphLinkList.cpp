#include<iostream>
using namespace std;
class LinkList
{
private:
        int virtexNO;
        LinkList* next;
public:
        LinkList(int virtexNO)
        {
            this->virtexNO=virtexNO;
            next=NULL;
        }
        int getListNO()
        {
            return virtexNO;
        }
        void setVirtexNO(int virtexNO)
        {
            this->virtexNO=virtexNO;
        }
        LinkList* getNext()
        {
            return next;
        }
        void setNext(LinkList* next)
        {
            this->next=next;
        }
};
class Graph
{
private:
        int V;
        int E;
        LinkList** Adj;
public:
        Graph(int V,int E)
        {
            int i;
            this->V=V;
            this->E=E;
            Adj=new LinkList*[V];
			for(i=0;i<V;i++)
			{
				Adj[i]=new LinkList(i);
				Adj[i]->setVirtexNO(i);
				Adj[i]->setNext(Adj[i]);
			}
        }
        void InputData()
        {
            int x,y,i;
            cout<<"Enter the rout"<<endl;
            for(i=0;i<E;i++)
            {
                cin>>x>>y;
                LinkList* NewNode=new LinkList(y);
                LinkList* temp=Adj[x];
                while(temp->getNext() != Adj[x])
                {
                	temp=temp->getNext();
                }
                	temp->setNext(NewNode);
                	NewNode->setNext(Adj[x]);
            }
        }
         void PrintM()
         {
         		cout<<V<<" "<<E<<endl;
         		cout<<"Adj Value that Inserted"<<endl;
     			for(int i=0;i<V;i++)
				 {
				 	cout<<Adj[i]->getListNO()<<" ";
				 }    
				 cout<<endl;
				 cout<<"After inserting"<<endl;
				for(int i=0;i<V;i++)
				 {
				 	LinkList* temp=Adj[i];
				 	while(temp->getNext()!=Adj[i])
                	{	
                		cout<<temp->getListNO()<<" ";
                		temp=temp->getNext();
                	}
                	cout<<temp->getListNO()<<endl;
				 }
            
         }

};

int main()
{
    Graph g(4,5);
    g.InputData();
    g.PrintM();

    return 0;
}
