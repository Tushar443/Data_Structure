#include<iostream>
using namespace std;
class Graph
{
private:
        int V;
        int E;
        int** matrix;
        int* VirTable;
        int* DisTable;
        int* ParentTable;
public:
        Graph(int V,int E)
        {
            this->V=V;
            this->E=E;
            VirTable=new int[V];
            DisTable=new int[V];
            ParentTable=new int[V];
            matrix=new int*[V];
            for(int i=0;i<V;i++)
                matrix[i]=new int[V];
            for(int i=0;i<V;i++)
                for(int j=0;j<V;j++)
                    matrix[i][j]=99999;
        }
        void InputData(int x,int y,int z)
        {
            //int x,y,z;
            //cout<<"Enter the Rout "<<endl;
            for(int i=0;i<E;i++)
            {
               // cin>>x>>y>>z;
                matrix[x][y]=z;
                //matrix[y][x]=z;
            }
        }
        int AllVisited()
        {
        	for(int i=0;i<V;i++)
        	{
        		if(VirTable[i]==0)
        			return 1;
			}
			return 0;
		}
        void DijKtraAlgo(int start)
        {
        	int i,u,v,w,min;
        	for(i=0;i<V;i++)
        	{
        		cout<<"for"<<endl;
        		VirTable[i]=0;
        		DisTable[i]=99999;
        		ParentTable[i]=-1;
			}
			DisTable[start]=0;
			min=99999;
			while(AllVisited())
			{
				cout<<"while"<<endl;
				for(i=0;i<V;i++)
				{
					cout<<"for inside while"<<endl;
					if(min>DisTable[i]){
					
						min=DisTable[i];
						u=i;
					}
				}
				VirTable[min]=1;
				for(i=0;i<V;i++)
				{
					cout<<"Relax"<<endl;
					if(matrix[u][i] != 99999)
						RelaxFunction(u,i,matrix[u][i]);
				}
			}
			
		}
		int RelaxFunction(int u,int v,int w)
		{
			if(DisTable[v] > DisTable[u]+w)
			{
				cout<<"Relax if"<<endl;
				DisTable[v]=DisTable[u]+w;
				ParentTable[v]=u;
			}
		}
         void print()
         {
            for(int i = 0; i < V; i++)
            {
                for(int j = 0; j < V; j++)
                    cout<<matrix[i][j]<<"\t";
                cout<<endl;
            }
        }

};

int main()
{
    Graph g(5,9);
    g.InputData(0,1,10);
    g.InputData(0,2,5);
    g.InputData(2,1,3);
    g.InputData(2,4,2);
    g.InputData(1,2,2);
    g.InputData(1,3,1);
    g.InputData(3,4,4);
    g.InputData(4,0,7);
    g.InputData(4,3,6);
    g.print();
    g.DijKtraAlgo(0);
   

    return 0;
}
