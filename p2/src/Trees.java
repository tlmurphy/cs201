import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Trees, main class.
 */
public class Trees {

    public Trees() {
        BST tree = new BST();
        RBTree rbTree = new RBTree();
        Scanner sc = null;
        try {
            sc = new Scanner(new File("myText"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        while (sc.hasNextInt()) {
            String word = sc.next();
            word = word.toLowerCase();
            word = word.replaceAll("[^a-zA-Z\\s]", "").replaceAll("\\s+", " ");
            tree.insert(word);
            rbTree.insertRBT(rbTree.getRoot(), word);
        }

        rbTree.deleteRBT(100);
        rbTree.levelOrderTraversal(rbTree.getRoot());
        tree.levelOrderTraversal(tree.getRoot());
//
//        tree.delete("i");
//
//        tree.levelOrderTraversal(tree.getRoot());
//
//        tree.delete("heres");
//
//        tree.levelOrderTraversal(tree.getRoot());
//
//        tree.delete("whateveridont");
//
//        tree.levelOrderTraversal(tree.getRoot());
    }

    public static void main(String[] args) {
        new Trees();
    }

}
