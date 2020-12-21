#include <iostream>
using namespace std;

int main(){
    int arr[]  = {1,2,3,4,5,6,7,8,9,10};
   
    int search=55,minLength=0,maxLength=9,mid=0,i=0,flag=0;
    while(minLength<=maxLength){
        mid =(minLength + maxLength)/2;
        if(search<arr[mid]){
            maxLength = mid-1;
        }
        else if(search > arr[mid]){
 
            minLength = mid+1;
        }
        else {
                flag = 1;
                break;
        }
    }
if(flag == 1)
    cout<<"Found"<<endl;
else
    cout<<"Not Found"<<endl;
    return 0;
}
