package CollectionsQuestion;

public class QueueFromStack {

    public static int[] stack(){
        return new int[0];
    }
}

class Queue{

    int[] arr;
    int top;
    int bottom;
    int size;

    public Queue(){
        top=0;
        bottom=0;
        size=0;
        arr= new int[0];
    }
    public Queue(int size){
        top=0;
        bottom=0;
        size=0;
        arr= new int[size];
    }

    public int enqueue(int data){
        if(this.size == 0){
            arr[0] = data;
            bottom++;
        }else{
            for(int i=0;i<size;i++){

            }

        }

        return data;
    }



}
