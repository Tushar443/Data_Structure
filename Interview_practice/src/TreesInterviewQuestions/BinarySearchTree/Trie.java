package TreesInterviewQuestions.BinarySearchTree;

public class Trie {
    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public static void main() {
        Trie tr = new Trie();
        tr.insert("API");
        tr.insert("APIS");
        tr.insert("BCI");
        System.out.println(tr.findString("BC"));
        System.out.println("Traverse");

    }

    public void insert(String str) {
        TrieNode currentNode = root;
        char[] arr = str.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            char ch = arr[i];
            TrieNode node = currentNode.children.get(ch);
            if (node == null) {
                node = new TrieNode();
                currentNode.children.put(ch, node);
            }
            currentNode = node;
        }
        currentNode.endOfString = true;
        System.out.println("Insert Successfully = " + str);
    }

    public boolean findString(String str) {
        TrieNode currentNode = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            TrieNode node = currentNode.children.get(ch);
            if (node == null) {
                System.out.println("String is Not Present");
                return false;
            } else {
                currentNode = node;
            }
        }
        if (currentNode.endOfString) {
            System.out.println("String found");
            return true;
        }
        System.out.println("String NOT found ");
        return false;
    }
}
