#include<iostream>
using namespace std;
class Graph
{
private:
        int V;
        int E;
        int brr[10];
        int top;
        int** matrix;
public:
        Graph(int V,int E)
        {
            this->V=V;
            this->E=E;
            for(int j=0;j<9;j++)
            	brr[j]=-1;
            top=-1;
            matrix=new int*[V];
            for(int i=0;i<V;i++)
                matrix[i]=new int[V];
            for(int i=0;i<V;i++)
                for(int j=0;j<V;j++)
                    matrix[i][j]=0;
        }
        
        void InputData()
        {
            int x,y;
            cout<<"Enter the Rout "<<endl;
            for(int i=0;i<E;i++)
            {
                cin>>x>>y;
                matrix[x][y]=1;
                matrix[y][x]=1;
            }
        }
        int Visited(int x)
        {
        	 int i;
        	for(i=0;i<V;i++)
        	{
        		if(brr[i]==x)
        			return 0;
			}
			brr[++top]=x;
			return 1;
		}
        void BFS(int x)
        {
        	int arr[V]={-1};
        	int front=-1,rear=-1,top=-1;
        	Visited(x);
        	arr[++rear]=x;
        	while(front!=rear)
        	{
        		int z=arr[++front];
        		cout<<z<<" ";
        		for(int y=0;y<V;y++)
        		{
					if(matrix[z][y]!=0 && Visited(y))
        				arr[++rear]=y;
        		}
        	}
    	}
    	void BDT(int x)
    	{
    		for(int j=0;j<9;j++)
            	brr[j]=-1;
            top=-1;
    		int BDS[V]={-1};
    		int top1=-1;
    		Visited(x);
    		BDS[++top1]=x;
    		while(top1!=-1)
    		{
    			int z=BDS[top1--];
    			cout<<z<<" ";
    			for(int y=0;y<V;y++)
    			{
    				if(matrix[z][y]!=0 && Visited(y))
    					BDS[++top1]=y;
				}
			}
		}
         void print()
         {
            for(int i = 0; i < V; i++)
            {
                for(int j = 0; j < V; j++)
                    cout<<matrix[i][j]<<" ";
                cout<<endl;
            }
        }

};

int main()
{
    Graph g(4,4);
    g.InputData();
    g.print();
  	cout<<"BFS traversal"<<endl;
  	g.BFS(0);
  	cout<<endl;
  	cout<<"BDS traversal"<<endl;
  	g.BDT(0);
  
	
    return 0;
}
