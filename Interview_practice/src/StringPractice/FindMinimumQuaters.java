package StringPractice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FindMinimumQuaters {

    public static void main(){
        String[] s = {"2Q22","1Q23","1Q22","4Q23"};
//        System.out.println(findQuaters(s));

        /**
         * items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]],
         */
        List<List<String>> items = new ArrayList<>();
        items.add(new ArrayList<>(Arrays.asList("phone","blue","pixel")));
        items.add(new ArrayList<>(Arrays.asList("computer","silver","phone")));
        items.add(new ArrayList<>(Arrays.asList("phone","gold","iphone")));
        String rk = "type", rv = "phone";
        System.out.println("Count matches " +countMatches(items,rk,rv));
    }

    public static int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        return (int) items.stream().flatMap(list -> list.stream().filter(item ->{
            if(!ruleKey.equals("name")){
                return item.equals(ruleValue);
            }
            return false;
        })).count();
    }

    public static String findQuaters(String[] s){
        String result= null;
        int minYear = 999;
        int minQt = 99;
        for(int i = 0 ; i< s.length;i++){
            String val = s[i];
            String[] arr = val.split("Q");
            int actualYear = Integer.parseInt(arr[1]);
            int actualQt = Integer.parseInt(arr[0]);
            if(minYear == actualYear){
                if(minQt >= actualQt){
                    minQt=actualQt;
                }
            }
            if(minYear > actualYear){
                minYear = actualYear;
                minQt = actualQt;
            }
        }
        result = minQt +"Q"+minYear;
        return result;
    }
}
