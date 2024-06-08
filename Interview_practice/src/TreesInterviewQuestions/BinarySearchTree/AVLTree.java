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
//        al.insert(70);
//        al.insert(50);
//        al.insert(40);
//        al.insert(60);
//        al.insert(80);
//        al.insert(90);
//        al.insert(75);
//        al.insert(30);
//        al.insert(20);
//        al.insert(10);
        al.insert(5);
        al.insert(10);
        al.insert(15);
        al.insert(20);
        al.inOrder(al.root);
//        System.out.println(al.depth);
//        System.out.println(al.findCondition(al.root.right));
    }

    public void insert(int val) {
        root = insertNode(root, val);
    }

    private BinaryNode insertNode(BinaryNode node, int value) {
        if (node == null) {
            BinaryNode newNode = new BinaryNode(value);
            newNode.height = 1;
            return newNode;
        } else if (node.value >= value) {
            node.left = insertNode(node.left, value);
        } else {
            node.right = insertNode(node.right, value);
        }

        node.height = 1 + Math.max(getHeight(node.left), getHeight(node.right));
        int balance = getBalance(node);
        if (balance > 1 && value < node.left.value) {
            //LL rotation
            return rotateRight(node);
        }
        if (balance > 1 && value > node.right.value) {
            // LR rotation
            node.left = rotateLeft(node.left);
            return rotateRight(node);
        }

        if (balance < -1 && value > node.right.value) {
            // RR rotation
            return rotateLeft(node);
        }

        if (balance < -1 && value < node.right.value) {
            // RL rotation
            node.right = rotateRight(node.right);
            return rotateLeft(node);
        }
        return node;
    }

    private BinaryNode minimumNode(BinaryNode node) {
        if (node.left == null) {
            return node;
        }
        return minimumNode(node.left);
    }

    public BinaryNode deleteNode(BinaryNode node, int value) {
        if (node == null) {
            return null;
        } else if (node.value > value) {
            node.left = deleteNode(node.left, value);
        } else if (node.value < value) {
            node.right = deleteNode(node.right, value);
        } else {
            if (node.left != null && node.right != null) {
                BinaryNode temp = node;
                BinaryNode minimumNode = minimumNode(node.right);
                node.value = minimumNode.value;
                node.right = deleteNode(node.right,minimumNode.value);
            } else if (node.left != null) {
                node = node.left;
            } else if (node.right != null) {
                node = node.right;
            }
        }

        int balance = getBalance(node);

        if(balance > 1 && getBalance(node.left) >= 0){
            //LL
            return rotateRight(node);
        }
        if(balance > 1 && getBalance(node.left) < 0){
            //LR
            node.left = rotateLeft(node.left);
            return rotateRight(node);

        }
        if(balance > -1 && getBalance(node.right) <= 0){
            //RR
            return rotateLeft(node);
        }
        if(balance > -1 && getBalance(node.right) > 0){
            //RL
            node.right = rotateRight(node.right);
            return rotateLeft(node);
        }
        return node;
    }

    public BinaryNode findLeafNode(BinaryNode currentNode) {
        if (currentNode != null) {
            if (currentNode.left == null && currentNode.right == null) {
                return currentNode;
            } else if (currentNode.left != null) {
                return findLeafNode(currentNode.left);
            } else if (currentNode.right != null) {
                return findLeafNode(currentNode.right);
            }
        }
        return null;
    }

    public BinaryNode rotateRight(BinaryNode disBalanced) {
        BinaryNode newRoot = disBalanced.left;
        disBalanced.left = disBalanced.left.right;
        newRoot.right = disBalanced;
        disBalanced.height = 1 + Math.max(getHeight(disBalanced.left), getHeight(disBalanced.right));
        newRoot.height = 1 + Math.max(getHeight(newRoot.left), getHeight(newRoot.right));
        return newRoot;
    }

    public BinaryNode rotateLeft(BinaryNode disBalanced) {
        BinaryNode newRoot = disBalanced.right;
        disBalanced.right = disBalanced.right.left;
        newRoot.left = disBalanced;
        disBalanced.height = 1 + Math.max(getHeight(disBalanced.left), getHeight(disBalanced.right));
        newRoot.height = 1 + Math.max(getHeight(newRoot.left), getHeight(newRoot.right));
        return newRoot;
    }

    public StringBuilder findCondition(BinaryNode node) {
        //LL,LR,RR,RL
        StringBuilder sb = new StringBuilder();
        if (node == null) {
            return null;
        }
        if (node.left != null) {
            sb.append("L");
            sb.append(findCondition(node.left));
        } else if (node.right != null) {
            sb.append("R");
            sb.append(findCondition(node.right));
        } else {
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

    public int getHeight(BinaryNode node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    public int getBalance(BinaryNode node) {
        if (node == null) {
            return 0;
        }
        return getHeight(node.left) - getHeight(node.right);
    }

}
