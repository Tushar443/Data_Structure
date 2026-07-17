package DivideAndConquerAlgorithm;

public class MinimumCostToReachEnd {

    public static void main(){
        int[][] arr =
        {
          {4,7,8,6,4},
          {6,7,3,9,2},
          {3,8,1,2,4},
          {7,1,7,3,7},
          {2,9,8,9,3}
        };
        int cost = 25;
//        System.out.println(findMinCost(arr, arr.length-1, arr[0].length-1));
        System.out.println(findMinFromCost(arr,arr.length-1, arr[0].length-1,cost));
    }

    //With given cost
    public static int findMinFromCost(int[][] arr,int row ,int col,int cost){
        if(cost < 0){
            return 0;
        }
        if(row == 0 && col == 0){
            return  (arr[0][0] - cost == 0) ?  1 : 0;
        }
        if(row == 0){
            return findMinFromCost(arr, 0, col-1, cost-arr[row][col]);
        }
        if(col == 0){
            return findMinFromCost(arr, row-1, 0, cost-arr[row][col]);
        }
        int previousRow = findMinFromCost(arr, row-1, col, cost-arr[row][col]);
        int previousCol = findMinFromCost(arr, row, col-1, cost-arr[row][col]);
        return previousCol+previousRow;
    }


    public static int findMinCost(int[][] cost, int row ,int col){
        if(col == -1 || row == -1){
            return Integer.MAX_VALUE;
        }
        if(col == 0 && row==0){
            return cost[0][0];
        }
        int min1 = findMinCost(cost, row, col-1);
        int min2 = findMinCost(cost, row-1, col);
        int currentCost = Math.min(min1,min2);
        return currentCost + cost[row][col];
    }
}
