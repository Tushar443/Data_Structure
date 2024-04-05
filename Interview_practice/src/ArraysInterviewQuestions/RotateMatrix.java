package ArraysInterviewQuestions;

public class RotateMatrix {

    public static Boolean rotateMatrix(){
        int [][] arr = {{1,2,3},{4,5,6},{7,8,9}};
        if(arr.length == 0 || arr.length != arr[0].length) return false;
        System.out.println("@ Before @");
        traverse(arr);
        int n = arr.length;
        for(int i = 0; i<n/2;i++){
            
        }


        System.out.println("# After #");
        traverse(arr);
    }

    public static void traverse(int[][] arr){
        for(int[] i :arr){
            for(int j : i){
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
}
