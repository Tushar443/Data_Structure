package TreesInterviewQuestions.BinarySearchTree;

public class BinaryNode {
    BinaryNode right;
    BinaryNode left;
    int value;
    int height;
    public BinaryNode(int value) {
        this.value = value;
    }

    @Override
    public String toString() {
        String s ="value = "+value+ " height = "+height + " $$##";
        return s;
    }
}
