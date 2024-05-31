package StactAndQuesuesInterviewQuestions.ShelterAnimal;

public abstract class Animal {
    int order;
    String name;

    public Animal(String name) {
        this.name = name;
    }

    abstract String name();

    public int getOrder() {
        return order;
    }

    public void setOrder(int order) {
        this.order = order;
    }

    public boolean isOlderThan(Animal a){
        return this.order < a.order;
    }
}
