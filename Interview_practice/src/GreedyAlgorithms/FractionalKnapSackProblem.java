package GreedyAlgorithms;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.concurrent.atomic.AtomicInteger;

public class FractionalKnapSackProblem {
    public static void main(){
        SackBox sackBox1 = new SackBox(20,60);
        SackBox sackBox2 = new SackBox(30,120);
        SackBox sackBox3 = new SackBox(10,60);
        SackBox sackBox4 = new SackBox(50,0);
        ArrayList<SackBox> arr = new ArrayList<>();
        arr.add(sackBox1);
        arr.add(sackBox2);
        arr.add(sackBox3);

        FractionalProblem(arr,sackBox4);

    }

    private static void FractionalProblem(ArrayList<SackBox> arr, SackBox sackBox4) {
        Comparator<SackBox> comparator = (o1, o2)->{
           if(o2.ratio > o1.ratio){
               return 1;
           }
            return -1;
        };

        Collections.sort(arr,comparator);
        int weight = 0 ;
            arr.stream().forEach(sackBox -> {


            });
        }
}
