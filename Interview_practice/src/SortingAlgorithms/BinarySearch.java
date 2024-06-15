package SortingAlgorithms;

public class BinarySearch {

    public static void main(){
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        int found = binarySearch(arr,0,arr.length-1,1);
        System.out.println("found at index = "+ found);
    }

    public static int binarySearch(int[] arr,int left,int right,int value){
        int mid = 0;
        while(left<=right){
             mid = (left+right)/2;
            if(value < arr[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return mid;
    }
}
