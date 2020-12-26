#include<iostream>
using namespace std;
class  Node
{
private:
    int data;
    Node* next;
public:
     Node(){
         data=0;
         next=NULL;
     }
     Node(int data){this->data=data;next = NULL;}
    ~ Node(){
        next =NULL;
    }
    void setNext(Node* next){
        this->next=next;
    }
    Node* getNext(){
        return next;
    }
    int getData(){
        return data;
    }
};
class QueueLik{
    private :
        Node* front;
        Node* rear;
    public :
        QueueLik(){
            front = rear=NULL;
        }
        ~QueueLik(){
            front = rear=NULL;
        }
        
        bool isEmpty(){
            if(front==NULL || rear == NULL){
                front=rear=NULL;
                return true;
            }
            return false;
        }
        void Enqueue(int data){
            Node* node = new Node(data);
            if(front == NULL && rear == NULL)
                front = rear=node;
            
            else{
                node->setNext(rear);
                rear=node;
            }
        }
        Node* Dequeue(){
            Node* temp1= new Node();
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return temp1;
            }else{
                Node* temp= rear;
                 if(front == rear && front !=NULL && rear!=NULL){
                    return front;
                    front=rear=NULL;
                }
                while (front != temp->getNext())
                {
                    temp=temp->getNext();
                }
               
                 temp1=front;
                front = temp;
                front->setNext(NULL);
                
            }
            return temp1;
        }
};
int main(){
    QueueLik q;
    cout<<q.Dequeue()->getData()<<endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    // q.Enqueue(60);
    // q.Enqueue(70);
    cout<<q.Dequeue()->getData()<<endl;
    cout<<q.Dequeue()->getData()<<endl;
    cout<<q.Dequeue()->getData()<<endl;
    cout<<q.Dequeue()->getData()<<endl;
    cout<<q.Dequeue()->getData()<<endl;
    // cout<<q.Dequeue()->getData()<<endl;
    // cout<<q.Dequeue()->getData()<<endl;
    // cout<<q.Dequeue()->getData()<<endl;

    return 0;
}