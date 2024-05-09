package StringPractice;

import java.util.Arrays;

public class ReverseStringPrefix {
        public static String reversePrefix(String word, char ch) {
            char[] arr = word.toCharArray();
            int index = 0;
            for(int i=0;i<arr.length ;i++){
                if(arr[i]==ch){
                    index = i;
                    break;
                }
            }
            StringBuilder sb = new StringBuilder();
            if(index == 0){
                return word;
            }
            if(index > 0) {
                for (int i = index ; i >=0; i--) {
                    sb.append(arr[i]);
                }
            }

            for(int i = index+1 ; i < arr.length; i++){
                sb.append(arr[i]);
            }
            return sb.toString();
        }
}
