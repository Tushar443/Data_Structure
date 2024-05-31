package StactAndQuesuesInterviewQuestions.ShelterAnimal;

public class Dog extends Animal{

    public Dog(String name) {
        super(name);
    }

    @Override
    String name() {
        return "Dog : "+name;
    }
}
