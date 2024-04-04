#include<iostream>
using namespace std;
class Graph
{
private:
        int V;
        int E;
        int** matrix;
public:
        Graph(int V,int E)
        {
            this->V=V;
            this->E=E;
            matrix=new int*[V];
            for(int i=0;i<V;i++)
                matrix[i]=new int[V];
            for(int i=0;i<V;i++)
                for(int j=0;j<V;j++)
                  matrix[i][j]=99999;
        }
        void InputData()
        {
            int x,y,z,c=0;
            cout<<"Enter the Rout and Distance "<<endl;
            while(1)
            {
            	cin>>x>>y>>z;
            	if(z==-1)
            		break;
                    matrix[x][y]=z;
            }
        }
        void FloydAlgo()
        {
        	int k,i,j;
        	for(k=0;k<V;k++)
        	{
        		for(i=0;i<V;i++)
        		{
        			for(j=0;j<V;j++)
        			{
        				if(matrix[i][k]+matrix[k][j]<matrix[i][j])
        					matrix[i][j]=matrix[i][k]+matrix[k][j];
        			}
        		}
        	}
		}	
         void Print()
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
    Graph g(4,4);
    g.InputData();
    g.Print();
    g.FloydAlgo();
    cout<<"After Algorithm"<<endl;
	g.Print();
    return 0;
}
