package StactAndQuesuesInterviewQuestions.ShelterAnimal;

import java.util.LinkedList;

public class AnimalQueue {
    LinkedList<Dog> dogs = new LinkedList<>();
    LinkedList<Cat> cats = new LinkedList<>();
    int order = 0 ;

    public void enqueue(Animal animal){
        animal.setOrder(order);
        order++;
        if(animal instanceof Dog){
            dogs.addLast((Dog) animal);
        }else if(animal instanceof Cat){
            cats.addLast((Cat) animal);
        }
    }

    public Animal dequeueAny(){
        if(dogs.isEmpty()){
            return dequeueCat();
        }else if(cats.isEmpty()){
            return dequeueDog();
        }
        Dog dog = dogs.peek();
        Cat cat = cats.peek();
        if(dog.isOlderThan(cat)){
            return dequeueDog();
        }else{
            return dequeueCat();
        }
    }

    public Dog dequeueDog(){
       return dogs.poll();
    }
    public Dog peekDog(){
        return dogs.peek();
    }

    public Cat dequeueCat(){
       return cats.poll();
    }
    public Cat peekCat(){
        return cats.peek();
    }

    public static void main() {
        AnimalQueue animalQueue = new AnimalQueue();
        animalQueue.enqueue(new Cat("Cegi"));
        animalQueue.enqueue(new Cat("cebi"));
        animalQueue.enqueue(new Dog("Dei"));
        animalQueue.enqueue(new Cat("cer"));
        animalQueue.enqueue(new Dog("der"));
        animalQueue.enqueue(new Cat("cur"));
        animalQueue.enqueue(new Dog("dugi"));
        animalQueue.enqueue(new Dog("dru"));

        System.out.println(animalQueue.dequeueAny().name());
        System.out.println(animalQueue.dequeueDog().name());
        System.out.println(animalQueue.dequeueCat().name());
    }
}
