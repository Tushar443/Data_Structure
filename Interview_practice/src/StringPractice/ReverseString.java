package StringPractice;

import java.util.Arrays;

public class ReverseString {

    public static String reverseString(String s){
        char[] arr = s.toCharArray();
        int last = arr.length-1;
        for(int i = 0 ;i < arr.length /2 ;i++){
            char temp =arr[i];
            arr[i] = arr[last];
            arr[last] = temp;
            last--;
        }

        return new String(arr);
    }

}
