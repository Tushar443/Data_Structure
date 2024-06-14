package TreesInterviewQuestions.BinarySearchTree;

public class BinaryHeap {

    int[] arr;
    int sizeOfArray;

    public BinaryHeap(int size) {
        arr = new int[size + 1];
        this.sizeOfArray = 0;
    }

    public boolean isEmpty() {
        if (sizeOfArray == 0) {
            return true;
        }
        return false;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("is Empty");
            return -1;
        } else {
            return arr[1];
        }
    }

    public int getSizeOfBinaryHeap() {
        return sizeOfArray;
    }

    public void levelOrder() {
        for (int i = 1; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public void heapifyBottomToTop(int index, String heapType) {
        if (index <= 1) {
            return;
        }
        int parent = index / 2;
        if (heapType.equalsIgnoreCase("min")) {
            if (arr[parent] > arr[index]) {
                int temp = arr[parent];
                arr[parent] = arr[index];
                arr[index] = temp;
            }
        } else if (heapType.equalsIgnoreCase("max")) {
            if (arr[parent] < arr[index]) {
                int temp = arr[parent];
                arr[parent] = arr[index];
                arr[index] = temp;
            }
        }
        heapifyBottomToTop(parent,heapType);
    }

    public void heapifyTopTOBottom(int index,String heapType){
        int left = index*2;
        int right = index*2+1;
        int swapChild;
        if(sizeOfArray < left){
            return;
        }
        if(heapType.equalsIgnoreCase("max")){
            if(sizeOfArray == left){
                if(arr[index]<arr[left]){
                    int temp =arr[index];
                    arr[index] = arr[left];
                    arr[left] = temp;
                }
                return;
            }else{
                if(arr[left] > arr[right]){
                    swapChild = left;
                }else {
                    swapChild = right;
                }
                if(arr[index] < arr[swapChild]){
                    int temp =arr[index];
                    arr[index] = arr[swapChild];
                    arr[swapChild] = temp;
                }
            }
        }else if (heapType.equalsIgnoreCase("min")){
            if(sizeOfArray == left){
                if(arr[index] > arr[left]){
                    int temp =arr[index];
                    arr[index] = arr[left];
                    arr[left] = temp;
                }
                return;
            }else{
                if(arr[left] < arr[right]){
                    swapChild = left;
                }else {
                    swapChild = right;
                }
                if(arr[index] > arr[swapChild]){
                    int temp =arr[index];
                    arr[index] = arr[swapChild];
                    arr[swapChild] = temp;
                }
            }
        }


//        int child1 = index * 2;
//        int child2 = index * 2 + 1;
//        if (heapType.equalsIgnoreCase("min")) {
//            if(arr[child1] < arr[child2]){
//                if (arr[child1] < arr[index]){
//                    int temp = arr[child1];
//                    arr[child1] = arr[index];
//                    arr[index] = temp;
//                }
//            }else{
//                if (arr[child2] < arr[index]){
//                    int temp = arr[child2];
//                    arr[child2] = arr[index];
//                    arr[index] = temp;
//                }
//            }
//        } else if (heapType.equalsIgnoreCase("max")) {
//            if(arr[child1] > arr[child2]){
//                if (arr[child1] > arr[index]){
//                    int temp = arr[child1];
//                    arr[child1] = arr[index];
//                    arr[index] = temp;
//                }
//            }else{
//                if (arr[child2] > arr[index]){
//                    int temp = arr[child2];
//                    arr[child2] = arr[index];
//                    arr[index] = temp;
//                }
//            }
//        }
//        heapifyTopTOBottom(child1,heapType);
//        heapifyTopTOBottom(child2,heapType);
//
    }

    public void insertIntoBH(int value,String heapType) {
        arr[sizeOfArray+1]= value;
        sizeOfArray++;
        heapifyBottomToTop(sizeOfArray,heapType);
    }

    public int extractHeadFromBH(String heapType){
        if(isEmpty()){
            return -1;
        }else{
            int extratctHead = arr[1];
            arr[1] = arr[sizeOfArray];
            arr[sizeOfArray]=0;
            sizeOfArray--;
            heapifyTopTOBottom(1,heapType);
            return extratctHead;
        }
    }
    public static void main(){
        BinaryHeap binaryHeap = new BinaryHeap(5);
        String heapType = "max";
        binaryHeap.insertIntoBH(10,heapType);
        binaryHeap.insertIntoBH(5,heapType);
        binaryHeap.insertIntoBH(15,heapType);
        binaryHeap.insertIntoBH(1,heapType);

        binaryHeap.levelOrder();
        System.out.println("######");
        binaryHeap.extractHeadFromBH(heapType);
        binaryHeap.levelOrder();
    }
}
