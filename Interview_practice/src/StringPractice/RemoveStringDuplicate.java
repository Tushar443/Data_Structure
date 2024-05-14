package StringPractice;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Map;

public class RemoveStringDuplicate {

    public static String removeDuplicate(String s){
        char[] arr= s.toCharArray();
        HashSet<Character> set = new LinkedHashSet<>();
        for(char a : arr){
            if(!set.contains(a))
                set.add(a);
        }

        set.forEach(System.out::print);
        System.out.println();
        return null;
    }

    public static Map<Character,Integer> countOfChar(String s){
        Map<Character,Integer> map = new HashMap<>();
        char[] arr= s.toCharArray();
        for(Character a : arr){
            if(map.containsKey(a)){
                int count = map.get(a);
                count++;
                map.put(a,count);
            }else{
                map.put(a,0);
            }
        }
        return map;
    }
}
