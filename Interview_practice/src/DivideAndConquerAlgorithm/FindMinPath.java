package DivideAndConquerAlgorithm;

public class FindMinPath {

    public static void  main(){
       int[][] grid = {{1,3,1},{1,5,1},{4,2,1}};
        System.out.println(minPathSum(grid));
    }

    public static int minPathSum(int[][] grid) {
        int n = grid.length-1;
        int m = grid[0].length-1;
        return findMinPath(grid,n,m);

    }

    /**
     * 1 3 1
     * 1 5 1
     * 4 2 1
     */

    public static int findMinPath(int[][] grid,int n , int m){
        // System.out.println(n + " "+ m);
        if(n == 0 || m == 0){
            return grid[n][m];
        }
        int min1 = grid[n][m]+ findMinPath(grid,n-1,m);
        int min2 = grid[n][m]+ findMinPath(grid,n,m-1);

        return Math.min(min1,min2);

    }
   
}
