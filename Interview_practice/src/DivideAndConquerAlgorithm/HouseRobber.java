package DivideAndConquerAlgorithm;

public class HouseRobber {

    public static void main(){
        int[] arr = {6,7,1,30,8,2,4};
        System.out.println(maxValueHouses(arr,0));
    }

    public static int maxValueHouses(int[] arr, int currentHouse){
        if(currentHouse >= arr.length){
            return 0;
        }
        int stealFirstHouse = arr[currentHouse] + maxValueHouses(arr,currentHouse+2);
        int skipFirstHouse = maxValueHouses(arr,currentHouse+1);
        return Math.max(stealFirstHouse,skipFirstHouse);
    }
}
