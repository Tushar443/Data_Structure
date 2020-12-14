#include<iostrem>
using namespace std;
class Node
{
    private :
    int data;
    Node* next;
    public :
        Node(int data){
            this->data=data;
        }
        node(){}
        void setNext(Node* next)
        {
            this->next=next;
        }
        void setData(int data){
            this->data=data;
        }
        Node* getNext(){
            return next;
        }
        int getData(){
            return data;
        }
}

class  Tree
{
private:
    Node* head;
public:
    Tree(/* args */)
    {
        head = NULL;
    }

    ~Tree()
    {
        head=NULL;
    }

};

 

int main()
{
    return 0;
}