package StactAndQuesuesInterviewQuestions.ThreeElevatorsProblem;

import java.util.*;
import java.util.stream.Collectors;

import static java.util.Map.*;
import static java.util.Map.Entry.*;

public class ThreeElevatorsProblem {

    ArrayList<CircularQueue> liftList;
    int numberOfLift;
    int numberOfFloors;

    public ThreeElevatorsProblem(int numberOfLift, int numberOfFloors) {
        this.numberOfLift = numberOfLift;
        this.numberOfFloors = numberOfFloors;
        liftList = new ArrayList<>();
        for(int i = 0 ;i<numberOfFloors;i++){
            CircularQueue circularQueue = new CircularQueue(numberOfFloors);
            liftList.add(circularQueue);
        }
    }


    public int pressUp(){

        return 0;
    }

    public int pressDown(){
        return 0;
    }

    public int buttonOnFloor(int floor , String action){
        if(floor<numberOfFloors && floor > -1){
            if(action.equalsIgnoreCase("UP")){

            }else if(action.equalsIgnoreCase("Down")){

            }else {
                return -1;
            }
        }
        return floor;
    }

    public int travelLiftToWhichFloor(int floor, String action){
        if(floor<numberOfFloors && floor > -1){
            if(action.equalsIgnoreCase("UP")){

            }else if(action.equalsIgnoreCase("Down")){

            }else {
                return -1;
            }
        }
        return floor;
    }

    public static void main() {
        /**
         * Problem Statement
         * There are three elevators in a building that has twelve floors. Find an algorithm that needs to find the best possible way for the elevators to stop at any particular floor considering the traffic waiting for the lift on that floor. Consider the following constraints:
         *
         * there can be any number of people that need to use the lift at any given time
         * these people can be on any floor at any time (they do not particularly start at the ground floor)
         * there is no way of finding the accurate number of people waiting for the elevators on any floor
         * there are two buttons next to each of the elevators, for calling the lift up and down
         */

        ThreeElevatorsProblem threeElevatorsProblem = new ThreeElevatorsProblem(3,12);
        System.out.println(threeElevatorsProblem.pressUp());
    }
}
