#include<iostream>
using namespace std;

int main(){
    int arr[] = {35,33,42,10,14,19,27,44,26,31};
    cout<<"Before Sort"<<endl;
    for(int i = 0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    for(int i = 0;i<10;i++){
        int min = arr[i];
        int j=0;
        j= i-1;
        while(j>=0 && arr[j] > min){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = min;
    }

cout<<"After Sort"<<endl;
  for(int i = 0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}