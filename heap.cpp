#include<iostream>
using namespace std;
class Heap
{
private:
        int *arr;
        int capacity;
        int count;
public:
        Heap(int capacity)
        {
            count=0;
            this->capacity=capacity;
            arr=new int [capacity];
        }
        ~Heap()
        {
            delete [] arr;
            arr=NULL;
        }
        int* getArr()
        {
            return arr;
        }
        int getCount()
        {
            return count;
        }
        void setCount(int count)
        {
            this->count=count;
        }
        void setValue(int data)
        {
            arr[count++]=data;
        }
};
class HeapSortA
{
private:
        Heap* h;
public:
        BuildHeap()
        {
            h=NULL;
        }
        void HeapSort(int a[],int n)
        {
            CreateHeap(n);
            int oldSize,i,temp;
            BuildHeap(a,n);
        }
        void CreateHeap(int capacity)
        {
           h =new Heap(capacity);
        }
        void Input(int capacity)
        {
            cout<<"Enter the Element"<<endl;
            for(int i=0;i<capacity;i++)
            {
                int data;
                cin>>data;
                h->setValue(data);
            }
        }
        void BuildHeap(int a,int n)
        {
            for(int i=0;i<n;i++)
            {
                h->setValue(a[i]);
            }
            h->setCount(n);
        }
        void PercolateDown(Heap* h,int i)
        {

        }
        int Left(Heap*h,int i)
        {

        }
        int Right(Heap*h,int i)
        {

        }
};
int main()
{
    int arr[]={12,45,78,98,23,3,5,1,35,55};
   // Bubble(arr,10);
    return 0;
}
