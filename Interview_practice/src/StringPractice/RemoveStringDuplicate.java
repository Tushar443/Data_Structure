package StringPractice;

import java.util.*;

public class RemoveStringDuplicate {

    public static void main(){
        String s = "tusadcsjlcnsekjdehusedsldheuiasscs,csejseoifsehfselfsehisehfeifsefucidewdssdshdsdassdddcsdsr";
        String s1 = RemoveStringDuplicate.removeDuplicate(s);
        System.out.println(s1);

        Map<Character, Integer> map = RemoveStringDuplicate.countOfChar(s);
        map.forEach((key,value)-> System.out.println(key+ " "+ value));
//        System.out.println(map);
//        for (Map.Entry<Character,Integer> entry : map.entrySet()){
//            System.out.println(entry.getKey() + " "+ entry.getValue());
//        }
//        Set<Character> set = map.keySet();
//        for (Character c : set) {
//            System.out.println("key = " + c + " and value = " + map.get(c));
//        }
    }

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
