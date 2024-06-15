package SortingAlgorithms;

import TreesInterviewQuestions.BinarySearchTree.BinaryHeap;

public class SortingAlgorithmss {
    public static void main() {
        int[] arr = {8,4,2,9,1,3,5,7,10};
//        bubbleSort(arr);
//        selectionSort(arr);
//        insertionSort(arr);
//        mergeSort(arr,0,arr.length-1);
//        QuickSort(arr,0,arr.length-1);
        HeapSort(arr);
        printArray(arr);

    }

    public static void HeapSort(int[] arr){
        BinaryHeap br = new BinaryHeap(arr.length);
        for(int i = 0; i<arr.length;i++){
            br.insertIntoBH(arr[i],"min");
        }
        for(int i = 0; i<arr.length;i++){
            arr[i] = br.extractHeadFromBH("min");
        }
    }

    public static void QuickSort(int[] arr , int start, int end){
        if(start < end){
            int pivot = partition(arr,start,end);
            QuickSort(arr,start,pivot-1);
            QuickSort(arr,pivot+1,end);
        }
    }

    public static int partition(int[] arr, int start, int end){
        int pivot = end;
        int i = start-1;
        for(int j = start;j<=end;j++){
            if(arr[j] <= arr[pivot]){
                i++;
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        return i;
    }

    public static void mergeSort(int[] arr , int left,int right){
        if(left<right){
            int mid = (left+right)/2;
            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);
            merge(arr,left,mid,right);
        }
    }

    public static void merge(int[] arr , int left ,int middle,int right){
        int[] leftArr = new int[middle-left+2];
        int[] rightArr = new int[right-middle+1];

        for(int i = 0; i <= middle - left; i++){
            leftArr[i]=arr[left+i];
        }
        for(int i = 0; i < right - middle; i++){
            rightArr[i]=arr[middle+1+i];
        }

        leftArr[middle-left+1]= Integer.MAX_VALUE;
        rightArr[right-middle]= Integer.MAX_VALUE;

        int i=0,j=0;
        for(int k = left ;k<=right ; k++){
            if(leftArr[i] < rightArr[j]){
                arr[k] = leftArr[i];
                i++;
            }else{
                arr[k] = rightArr[j];
                j++;
            }
        }
    }

    private static void insertionSort(int[] arr) {
        for(int i = 1 ; i< arr.length;i++){
            int temp = arr[i] , j = i;
            while(j>0 && arr[j-1] > temp){
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = temp;
        }
    }

    private static void selectionSort(int[] arr) {
        int min;
        for (int i = 0; i < arr.length; i++) {
            min = i;
            for (int j = i+1; j < arr.length; j++) {
                if(arr[min] > arr[j]){
                    min = j;
                }
            }
            if(min!= i){
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
        }
    }
    public static void bubbleSort(int[]arr){
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }


    public static void printArray(int[] arr){
        for(int i = 0;i<arr.length;i++){
            System.out.print(arr[i] + " ");
        }
    }
}
