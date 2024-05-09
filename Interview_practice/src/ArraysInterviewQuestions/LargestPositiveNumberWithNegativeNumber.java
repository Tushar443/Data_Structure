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
}
