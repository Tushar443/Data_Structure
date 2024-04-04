#include<iostream>
using namespace std;
class Graph
{
private:
        int V;
        int E;
        int brr[10];
        int** matrix;
public:
        Graph(int V,int E)
        {
            this->V=V;
            this->E=E;
            brr[10]={-1};
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
        	 int top=0,i;
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
        	brr[++top]=x;
        	arr[++rear]=x;
        	for(int y=0;y<V;y++)
        	{
        		if(matrix[x][y]!=0 && Visited(y))
        		{
        			arr[++rear]=y;
        		}
        	}
        	while(front!=rear)
        	{
        		cout<<arr[++front]<<" ";
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
    Graph g(4,5);
    g.InputData();
    g.print();
    g.BFS(1);

    return 0;
}
