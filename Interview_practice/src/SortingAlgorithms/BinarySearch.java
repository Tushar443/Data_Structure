package SortingAlgorithms;

public class BinarySearch {

    public static void main(){
        int[] arr = {1,3,4,5,6,7,8,9,10};
        int value = 2;
        int found = binarySearch(arr,0,arr.length-1,value);

        int closest = getClosestElementInSortedArray(arr,0,arr.length-1,2);
        System.out.println("found at index = "+ found);
        System.out.println("Closed to "+ value + " is = "+closest);
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

    private static int getClosestElementInSortedArray(int[] arr,int left,int right,int value){
        int mid = 0;
        int n = arr.length-1;
        while(left<=right){
            mid = (left+right)/2;
            if(value < arr[mid]){
                if (mid > 0 && value > arr[mid-1]){
                    return getClosetElement(arr[mid-1],arr[mid],value);
                }
                right = mid;
            }else {
                if(mid < n && value < arr[mid+1]){
                    return getClosetElement(arr[mid-1],arr[mid],value);
                }
                left = mid + 1;
            }
        }
        return mid;
    }

    private static int getClosetElement(int i, int i1, int value) {
        if(i-value < i1-value){
            return i;
        }else{
            return i1;
        }
    }
}
