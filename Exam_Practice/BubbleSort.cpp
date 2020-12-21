#include<iostream>
using namespace std;
int main(){
    int arr[]= {23,5,6,32,58,98,1,16,56};

for(int i= 0;i<8;i++){
    for(int j = 0;j<8;j++){
        if(arr[i]>arr[j]){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        else{
            continue;
        }
    }

    
}
for (int i = 0; i < 8; i++)
    {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
    cout<<"@@@@@@@@@@@ Asendeing @@@@@@@@"<<endl;
    for(int i= 0;i<8;i++){
    for(int j = 0;j<8;j++){
        if(arr[i]<arr[j]){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        else{
            continue;
        }
    }

    
}
for (int i = 0; i < 8; i++)
    {
        cout<<arr[i] <<" ";
    }
    return 0;
}