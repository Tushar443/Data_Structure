#include<iostream>
using namespace std;
void Bubble(int arr [],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int arr[]={12,45,78,98,23,3,5,1,35,55};
    Bubble(arr,10);
    return 0;
}
