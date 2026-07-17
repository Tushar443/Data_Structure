package StringPractice;

import java.sql.Struct;

public class LongestCommonPrefix {
    public static void main() {
        String arr[] = {"geeksforgeeks", "geeks",
                "geek", "geezer"};
        int n = arr.length;
        System.out.println("### Longest Common Prefix");
        System.out.println(commonPrefix(arr,0,n-1));
    }

    public static String commonPrefix(String[] arr ,int low , int high){
        if(low == high){
            return arr[low];
        }
        if(high > low){
            int mid = (low+high)/2;
            String string1 = commonPrefix(arr, low, mid);
            String string2 = commonPrefix(arr, mid + 1, high);
            return commonPrefixUntil(string1,string2);
        }
        return null;
    }

    private static String commonPrefixUntil(String string1, String string2) {
        String result = "";
        int n = Math.min(string1.length(),string2.length());
        for(int i = 0;i<n;i++){
            if(string1.charAt(i) != string2.charAt(i)){
                break;
            }
            result+=string1.charAt(i);
        }
        return result;
    }
}
