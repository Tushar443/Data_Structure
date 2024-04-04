#include<iostream>
using namespace std;
void SelectionSort(int arr [],int size)
{
    for(int i=0;i<size;i++)
    {
        int min=i;
        for(int j=0;j<size;j++)
        {

            if(arr[min]>arr[j])
                min=j;
            if(min!=i)
            {
                int temp=arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }
        }
    }
    for(int i=0;i<=9;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int arr[]={12,45,78,98,23,3,5,1,35,55};
    SelectionSort(arr,10);
    return 0;
}
