package SortingAlgorithms;

public class SortingAlgorithms {
    public static void main() {
        int[] arr = {23, 45, 32, 2, 5, 67, 46, 13};
//        bubbleSort(arr);
//        selectionSort(arr);
        insertionSort(arr);
        printArray(arr);

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
