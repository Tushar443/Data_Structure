package ArraysInterviewQuestions;

import java.util.*;
import java.util.stream.Stream;

public class LargestPositiveNumberWithNegativeNumber {

    public static int findMaxK(int[] nums) {
        int max = 0;
        HashSet<Integer> list = new HashSet<>();
        for(int i : nums){
            if(i > 0 && list.contains(-i) && i > max){
                max = i ;
            }else if(i < 0 && list.contains(-i) && -i > max ){
                max = -i;
            }else
                list.add(i);
        }
//        Collections.sort(list);
        System.out.println(list);
        /**
         * Alternative
         */
//        HashSet<Integer> list1 = new HashSet<Integer>();
//        int ans = -1;
//        for (int nu : nums) {
//            if (list1.contains(nu * -1)) {
//
//                ans = Math.max(ans, Math.abs(nu));
//            } else {
//
//                list1.add(nu);
//            }
//
//        }

        /**
         * Alternative 2
         */
//        for(int i=0;i<nums.length-1;i++){
//            for(int j=i+1;j<nums.length;j++){
//                if(nums[i] > 0 && nums[i] == -nums[j]){
//                    if(max == 0){
//                        max = nums[i];
//                    }else if(nums[i] > max){
//                        max = nums[i];
//                    }
//                }else if(nums[i] == -nums[j]){
//                    if(max == 0){
//                        max = -nums[i];
//                    }else if(-nums[i] > max){
//                        max = -nums[i];
//                    }
//                }
//            }
//
//        }
        if(max==0){
            return -1;
        }
        return max;
    }

    public static void main() {
        /**
         * Largest Positive Integer That Exists With Its Negative
         * Input: nums = [-1,2,-3,3]
         * Output: 3
         * Explanation: 3 is the only valid k we can find in the array.
         */
        System.out.println("@@@@##################@@@@");
        int[] nums = new int[]{-49, 8, 19, -39, 37, 22, -39, 4, 37, 8, 20, -2, -4, -5, 14, -14, -27, 24, 30, 3, -12, 19, 22, 28, -3, -6, 6, 22, 37, 27, 16, 27, -6, -49, 31, 29};
        int resultMax = LargestPositiveNumberWithNegativeNumber.findMaxK(nums);
        System.out.println("largest number = " + resultMax);
    }
}
