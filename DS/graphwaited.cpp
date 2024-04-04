#include<iostream>
#include<cstring>
using namespace std;
class Graph
{
private:
        int V;
        int E;
        int** matrix;
        string* mapping;
public:
        Graph(int V,int E)
        {
            this->V=V;
            this->E=E;
            matrix=new int*[V];
            mapping= new string[V];
            for(int i=0;i<V;i++)
                matrix[i]=new int[V];
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<V;j++)
                {
                    matrix[i][j]=0;
                    mapping[i]="";
                }
            }
        }
        int isConnected(string s,string d)
        {
        	return matrix[getIndex(s)][getIndex(d)];
		}
        int getIndex(string vertex)
		{
        	for(int  i = 0; i <V; i++)
			{
            	if( mapping[i] == "")
				{
               		 mapping[i] = vertex;
                	return i;
            	}
            	if( mapping[i] == vertex)
                	return i;                 
        	
    		}
    		return -1;
    	}
        void Mapping(string s,string p,int w)
        {
            matrix[getIndex(s)][getIndex(p)]=w;
            matrix[getIndex(p)][getIndex(s)]=w;
        }
        void InputData()
        {
            string x,y;
            int z;
            cout<<"Enter the Rout by cities name "<<endl;
            for(int i=0;i<E;i++)
            {
                cin>>x>>y>>z;
                Mapping(x,y,z);
            }
        }
        void BFSPrint()
        {
        	
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
    Graph g(4,5);
    g.InputData();
    g.print();
    while(1)
    {
    	string s,d;
		int z;
    	cout<<"Enrer to check two paths are connected or not"<<endl;
    	cin>>s>>d;
    	z=g.isConnected(s,d);
    	if(z!=0)
    		cout<<s<<" to "<<d<<" Distance is "<<z<<endl;
    	if(z==0)
    		break;
	}

    return 0;
}
