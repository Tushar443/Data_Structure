package GreedyAlgorithms;

public class SackBox {
    int weight;
    int value;
    public double ratio;

    public SackBox(int weight, int value) {
        this.weight = weight;
        this.value = value;
        this.ratio = value * 1.0 / weight;
    }

    @Override
    public String toString() {
        System.out.println(weight+" "+ value + " "+ratio);
        return "";
    }
}
