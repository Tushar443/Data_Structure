#include<iostream>
using namespace std;
void Quick(int arr [],int N,int BEG,int END,int *LOC)
{
    int temp,LEFT,RIGHT;
    LEFT=BEG;
    RIGHT=END;
    *LOC=BEG;
   PKIR:
    while(arr[RIGHT]>=arr[*LOC] && *LOC!=RIGHT)
        RIGHT--;
    if(*LOC==RIGHT)
        return;
    if(arr[RIGHT]<arr[*LOC])
    {
        temp=arr[RIGHT];
        arr[RIGHT]=arr[*LOC];
        arr[*LOC]=temp;
        *LOC=RIGHT;
    }
    goto IJIR;
   IJIR:
    while(arr[*LOC]>=arr[LEFT] && *LOC!=LEFT)
        LEFT++;
    if(*LOC==LEFT)
        return;
    if(arr[LEFT]>arr[*LOC])
    {
        temp=arr[LEFT];
        arr[LEFT]=arr[*LOC];
        arr[*LOC]=temp;
         *LOC=LEFT;
    }
    goto PKIR;
}
void QuickSort(int arr[],int N)
{
    int top=-1,BEG,END,LOC;
    int UPPER[10],LOWER[10];
    if(N>1)
    {
        top++;
        LOWER[top]=0;
        UPPER[top]=N-1;
    }
    while(top!=-1)
    {
        BEG=LOWER[top];
        END=UPPER[top];
        top--;
        Quick(arr,N,BEG,END,&LOC);
        if(BEG<LOC-1)
        {
            top++;
            LOWER[top]=BEG;
            UPPER[top]=LOC-1;

        }
        if(LOC+1<END)
        {
            top++;
            LOWER[top]=LOC+1;
            UPPER[top]=END;

        }

    }
}
int main()
{
    int n;
    cin>>n;
    int X[n]={44,33,11,55,77,90,40,60,99,22,88,66};
    QuickSort(arr,12);
    for(int i=0;i<12;i++)
        cout<<arr[i]<<" ";
    return 0;
}
