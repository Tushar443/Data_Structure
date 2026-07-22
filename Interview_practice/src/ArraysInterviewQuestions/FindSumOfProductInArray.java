package ArraysInterviewQuestions;

public class FindSumOfProductInArray {

    /**
     * arr    = {2,4,5,6}
     * output = {120,60,48,40}  4*5*6 =120
     */

    public static void main(){
        int[] arr={2,4,5,6};
       int[] demo =  findSumOfArray(arr);
        System.out.println("Ans");
        display(demo);
    }

    public static void display(int[] arr){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i] +" ");
        }
        System.out.println();
    }

    private static int[] findSumOfArray(int[] nums) {
        int [] left = new int[nums.length];
        int [] right = new int[nums.length];
        left[0]=1;
        for(int i=1;i<nums.length;i++){
            left [i] = nums[i-1]*left[i-1];
        }
        right[nums.length-1]=1;
        for(int i=nums.length-2;i>=0;i--){
            right[i] = nums[i+1]*right[i+1];
        }
        int ans[]=  new int[nums.length];
        System.out.println("Left");
        display(left);
        System.out.println("Right");
        display(right);
        for(int i=0;i<nums.length;i++){
            ans[i] = left[i]*right[i];
        }
        return ans;


//        int[] newArr = new int[arr.length];
//
//        for(int i= 0 ; i < arr.length ;i++){
//            int mul = 1;
//            for(int j = 0 ;j < arr.length ; j++) {
//                if (i == j) {
//                    continue;
//                }
//                mul *= arr[j];
//                newArr[i] = mul;
//            }
//        }
//        return  newArr;
    }
}
