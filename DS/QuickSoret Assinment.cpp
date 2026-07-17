#include<iostream>
using namespace std;
void Quick(int X[],int N,int LB,int UB,int *J)
{
    int temp,LEFT,RIGHT;
    LEFT=LB;
    RIGHT=UB;
    *J=LB;
   PKIR:
    while(X[RIGHT]>=X[*J] && *J!=RIGHT)
        RIGHT--;
    if(*J==RIGHT)
        return;
    if(X[RIGHT]<X[*J])
    {
        temp=X[RIGHT];
        X[RIGHT]=X[*J];
        X[*J]=temp;
        *J=RIGHT;
    }
    goto IJIR;
   IJIR:
    while(X[*J]>=X[LEFT] && *J!=LEFT)
        LEFT++;
    if(*J==LEFT)
        return;
    if(X[LEFT]>X[*J])
    {
        temp=X[LEFT];
        X[LEFT]=X[*J];
        X[*J]=temp;
         *J=LEFT;
    }
    goto PKIR;
}
void QuickSort(int X[],int N)
{
    int top=-1,LB,UB,J;
    int UPPER[10],LOWER[10];
    if(N>1)
    {
        top++;
        LOWER[top]=0;
        UPPER[top]=N-1;
    }
    while(top!=-1)
    {
        LB=LOWER[top];
        UB=UPPER[top];
        top--;
        Quick(X,N,LB,UB,&J);
        if(LB<J-1)
        {
            top++;
            LOWER[top]=LB;
            UPPER[top]=J-1;

        }
        if(J+1<UB)
        {
            top++;
            LOWER[top]=J+1;
            UPPER[top]=UB;

        }

    }
}
int main()
{
    int n;
    cin>>n;

    int X[n];

    for(int i=0;i<n;i++)
        cin>>X[i];
          QuickSort(X,n);
           for(int i=0;i<n;i++)
        cout<<X[i]<<" ";
    return 0;
}
