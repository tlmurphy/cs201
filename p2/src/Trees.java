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
            sc = new Scanner(new File("corpus copy"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        while (sc.hasNext()) {
            String word = sc.next();
            word = word.toLowerCase();
            word = word.replaceAll("[^a-zA-Z\\s]", "").replaceAll("\\s+", " ");
            tree.insert(tree.getRoot(), word);
            rbTree.insertRBT(rbTree.getRoot(), word);
        }

        rbTree.levelOrderTraversal(rbTree.getRoot());
        tree.levelOrderTraversal(tree.getRoot());

        tree.delete("fox");
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
