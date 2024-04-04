#include<iostream>
using namespace std;
void Insertion(int arr [],int size)
{
    int temp,k,i,j;
    for( i=1;i<=size;i++)
    {
        for( j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
            {
                 temp=arr[i];
                arr[i]=arr[j];
            }
            for( k=i;k>j;k++)
            {
                arr[k]=arr[k-1];
            }
            arr[k+1]=temp;
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
    Insertion(arr,10);
    return 0;
}
