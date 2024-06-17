package DivideAndConquerAlgorithm;

public class NumberFactor {

    public static void main(){
        System.out.println(numberFactor(4));
        System.out.println(numberFactor(5));
        System.out.println(numberFactor(6));
    }

    public static int numberFactor(int n){
        if(n==1 || n==0 || n==2){
            return 1;
        }
        if(n==3){
            return 2;// {1,1,1},{3}
        }

        int sub1 = numberFactor(n-1);
        int sub2= numberFactor(n-3);
        int sub3 = numberFactor(n-4);

        return sub1+sub2+sub3;

    }

}
