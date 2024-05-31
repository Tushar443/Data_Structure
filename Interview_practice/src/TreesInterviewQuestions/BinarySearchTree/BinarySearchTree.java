package TreesInterviewQuestions.BinarySearchTree;

import java.util.LinkedList;
import java.util.Queue;

public class BinarySearchTree {
    BinaryNode root;
    int depth;

    public BinarySearchTree() {
        root = null;
        depth = 0;
    }

    private BinaryNode insertNode(BinaryNode currentNode, int value) {
        if (currentNode == null) {
            BinaryNode newBinaryNode = new BinaryNode(value);
            return newBinaryNode;
        } else if (currentNode.value >= value) {
            currentNode.left = insertNode(currentNode.left,value);
            return currentNode;
        }else{
            currentNode.right = insertNode(currentNode.right,value);
            return currentNode;
        }
    }
    
    public void insert(int value){
       root = insertNode(root,value);
    }

    public void preOrder(BinaryNode root){
        if(root == null) return;
        System.out.print(root.value + " " );
        preOrder(root.left);
        preOrder(root.right);
    }

    public void postOrder(BinaryNode root){
        if(root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.value + " " );
    }

    public void inOrder(BinaryNode root){
        if(root == null) return;
        inOrder(root.left);
        System.out.print(root.value + " " );
        inOrder(root.right);
    }

    public void levelOrder(BinaryNode root){
        Queue<BinaryNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            BinaryNode node= queue.remove();
            System.out.print(node.value + " ");
            if(node.left != null){
                queue.add(node.left);
            }
            if(node.right != null){
                queue.add(node.right);
            }
        }
    }

    public BinaryNode search(BinaryNode root,int value){
        if(root.value == value) return root;
        if(root.value>=value) {
            System.out.print("left->");
           root = search(root.left,value);

        }else{
            System.out.print("right->");
           root = search(root.right,value);

        }
        return root;
    }

    public BinaryNode minimumNode(BinaryNode node){
        if(node.left == null){
            return node;
        }else{
            return minimumNode(node.left);
        }
    }

    public BinaryNode deleteNode(BinaryNode root , int value){
        if(root == null){
            System.out.println("value not found Tree is Empty");
            return null;
        }
        if(root.value < value){
            root.right = deleteNode(root.right,value);
        }else if(root.value > value){
           root.left = deleteNode(root.left,value);
        }else{
            if(root.left != null && root.right != null){
                BinaryNode temp = root;
                BinaryNode rightSuccessor = minimumNode(temp.right);
                root.value = rightSuccessor.value;
                root.right = deleteNode(root.right,rightSuccessor.value);
            }else if(root.left != null && root.right == null){
                root = root.left;
            }else if(root.left == null && root.right != null){
                root = root.right;
            }else{
                root = null;
            }
        }
        return root;
    }

    public static void main(){
        BinarySearchTree b = new BinarySearchTree();
        b.insert(70);
        b.insert(50);
        b.insert(90);
        b.insert(30);
        b.insert(60);
        b.insert(80);
        b.insert(100);
        b.insert(20);
        b.insert(40);
        b.preOrder(b.root);
        System.out.println();
        b.inOrder(b.root);
        System.out.println();
        b.postOrder(b.root);
        System.out.println();
        b.levelOrder(b.root);
        System.out.println();
        System.out.println(b.search(b.root,40).value);

        System.out.println(b.deleteNode(b.root,80));
        b.inOrder(b.root);
    }
}
