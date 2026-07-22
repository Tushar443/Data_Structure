

// int quiksor(int arr, int left ,int right ,int* pivoit){
//     loop_left :
//             if(arr!=NULL){
//                 if(arr[left] < arr[right]){
//                     right --;
//                 }
//                 if(arr[left]) >= arr[right]){
//                     int temp = arr[right];
//                     arr[right]  = arr[left];
//                     pivoit = right;
//                     goto loop_right;
//                 }
//             }
//     loop_right:
//             if(arr[left]< arr[right]){
//                 left ++;
//             }
//             if(arr[left] >= arr[right]){
//                 int temp = arr[left];
//                 arr[left] = arr[right];
//                 arr[right]= temp;
//                 pivoit=left; 
            
//                 goto loop_left;
//             }

// }

// void Quik(int[] arr,int n){

//     int left =0;
//     int right= n-1 ,top =-1,
//     int arr[10];
//     int arr2 [10];
//     int pivoit = arr[0];

//     if(arr!=NULL){
//         while(top == -1){
//             quiksor(arr,left,right,&pivoit);

//         }
//     }   

// }
// int n  =4;
// for(int i= 0;i<n;i++){
//     for(int j = 0;j<n;j++){
//         cout<<"*";
//     }
// }

// [100, 5, 50, 67, 10, 20, 8, 78]


