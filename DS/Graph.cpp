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

    return 0;
}
