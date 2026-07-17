package RecursionInterviewQuestions;

public class TowerOfHanoi {

    public static void main(){
        towerOfHanoi(5,'A','B','C');
        System.out.println("steps "+count);
    }
    static int count = 0;

    private static void towerOfHanoi(int n , char from ,char to,char aux){

        if(n==1){
            System.out.println("Move disk from = "+from+ " to = "+to +" n = "+n);
            return;
        }
        towerOfHanoi(n-1,from,aux,to);
        System.out.println("Move disk from = "+from+ " to = "+to + " n = "+n);
        count++;
        towerOfHanoi(n-1,aux,to ,from);
    }
}
