#include<iostream>
using namespace std;
void Zero(int arr [],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
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
    Zero(arr,10);
    return 0;
}
