package GreedyAlgorithms;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class ActivitySelectionProblem {

    public static void main(){
        Activity a1 = new Activity("A1",0,6);
        Activity a2 = new Activity("A2",3,4);
        Activity a3 = new Activity("A3",1,2);
        Activity a4 = new Activity("A4",5,8);
        Activity a5 = new Activity("A5",5,7);
        Activity a6 = new Activity("A6",8,9);
        ArrayList<Activity> activities = new ArrayList<>();
        activities.add(a1);
        activities.add(a2);
        activities.add(a3);
        activities.add(a4);
        activities.add(a5);
        activities.add(a6);
        ActivitySorting(activities);

    }

    public static void ActivitySorting(ArrayList<Activity> arrayList){
        Comparator<Activity> finishCompare = Comparator.comparingInt(Activity::getEndTime);
//                (o1, o2) -> o1.getEndTime() - o2.getEndTime();

        Collections.sort(arrayList,finishCompare);
        Activity previous = arrayList.get(0);
        System.out.println("\n\nRecommonded Schedule :\n "+arrayList.get(0));
        for(int i = 1;i<arrayList.size();i++){
            Activity activity = arrayList.get(i);
            if(activity.getStartTime() >= previous.getEndTime()){
                System.out.println(activity);
                previous = activity;
            }
        }

    }


}
