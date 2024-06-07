package TreesInterviewQuestions.BinarySearchTree;

public class AVLTree {

    BinaryNode root;
    int depth;

    public AVLTree() {
        root = null;
        depth = 0;
    }

    public static void main() {
        AVLTree al = new AVLTree();
        al.insert(70);
        al.insert(50);
        al.insert(40);
        al.insert(60);
        al.insert(80);
        al.insert(90);
        al.insert(75);
//        al.inOrder(al.root);
//        System.out.println(al.depth);
        System.out.println(al.findCondition(al.root.right));
    }

    public void insert(int val) {
        root = insertNode(root, val, 1);
        BinaryNode left = findLeafNode(root.left);
        BinaryNode right = findLeafNode(root.right);
    }

    private BinaryNode insertNode(BinaryNode root, int value, int height) {
        if (root == null) {
            BinaryNode node = new BinaryNode(value);
            node.height = height;
            depth=height;
            return node;
        } else if (root.value >= value) {
            root.left = insertNode(root.left, value, ++height);
        } else {
            root.right = insertNode(root.right, value, ++height);
        }
        return root;
    }

    public BinaryNode findLeafNode(BinaryNode currentNode) {
        if(currentNode != null){
            if(currentNode.left == null && currentNode.right == null){
                return currentNode;
            }else if(currentNode.left != null){
                return findLeafNode(currentNode.left);
            }else if(currentNode.right != null){
                return findLeafNode(currentNode.right);
            }
        }
        return null;
    }

    public BinaryNode rightRotation(BinaryNode disBalanced){
        BinaryNode newRoot = disBalanced.left;
        disBalanced.left = disBalanced.left.right;
        newRoot.right = disBalanced;
        disBalanced.height= 1+ Math.max(getHeight(disBalanced.left) , getHeight(disBalanced.right));
        newRoot.height= 1+ Math.max(getHeight(newRoot.left) , getHeight(newRoot.right));
        return newRoot;
    }

    public BinaryNode leftRotation(BinaryNode disBalanced){
        BinaryNode newRoot = disBalanced.right;
        disBalanced.right = disBalanced.right.left;
        newRoot.left = disBalanced;
        disBalanced.height= 1+ Math.max(getHeight(disBalanced.left) , getHeight(disBalanced.right));
        newRoot.height= 1+ Math.max(getHeight(newRoot.left) , getHeight(newRoot.right));
        return newRoot;
    }

    public StringBuilder findCondition(BinaryNode node){
        //LL,LR,RR,RL
        StringBuilder sb = new StringBuilder();
        if(node == null){
            return null;
        }
        if(node.left != null){
            sb.append("L");
            sb.append(findCondition(node.left));
        }else if (node.right != null){
            sb.append("R");
            sb.append(findCondition(node.right));
        }else{
            return sb;
        }
        return sb;
    }

    public void inOrder(BinaryNode root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.println(root.value + " height = " + root.height);
        inOrder(root.right);
    }

    public BinaryNode search(BinaryNode root, int value) {
        if (root.value == value) return root;
        if (root.value >= value) {
            System.out.print("left->");
            root = search(root.left, value);
        } else {
            System.out.print("right->");
            root = search(root.right, value);
        }
        return root;
    }

    public int getHeight(BinaryNode node){
        if(node == null){
            return 0;
        }
        return node.height;
    }

}
