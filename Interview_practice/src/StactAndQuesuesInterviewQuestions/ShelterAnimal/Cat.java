package StactAndQuesuesInterviewQuestions.ShelterAnimal;

public class Cat extends Animal{

    public Cat(String name) {
        super(name);
    }

    @Override
    String name() {
        return "Cat_ : "+name;
    }
}
