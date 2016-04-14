import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*************************************************************
 * Comparing Red-Black Trees with Binary Search Trees.       *
 * Written By: Trevor Murphy (with much help from Dr. Lusth) *
 *                                                           *
 * Program Invocation:                                       *
 * java -classpath classfiles Trees -1 data commands         *
 * Use -1 for BST and -2 for Red-Black Tree.                 *
 *************************************************************/

/**
 * Trees, main class.
 * Construct either a BST or RBT, insert words
 * from the file into the tree, then perform
 * actions based on the commands found in the
 * commands file.
 */
public class Trees {

    /**
     * Build tree and perform commands.
     * @param whichTree BST if 1, RBT if 2.
     * @param data Text file.
     * @param commands Commands file.
     */
    public Trees(int whichTree, String data, String commands) {
        BST tree;
        if (whichTree == 1) tree = new BST();
        else                tree = new RBTree();

        Scanner scData = null;
        Scanner scComm   = null;
        try {
            scData = new Scanner(new File(data));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        while (scData.hasNext()) {
            String word = scData.next();
            word = word.toLowerCase();
            word = word.replaceAll("[^a-zA-Z]", ""); // Replace non a-z char with ""
            if (!word.equals(""))
                tree.insert(word);
        }

        try {
            scComm = new Scanner(new File(commands));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        while (scComm.hasNext()) {
            String inputCommand = scComm.next();
            processCommand(inputCommand, tree, scComm);
        }
    }

    /**
     * Performs actions on a tree based on instructions
     * read from the commands file.
     * @param inputCommand The command to be performed.
     * @param tree RBT or BST.
     * @param s Scanner
     */
    private void processCommand(String inputCommand, BST tree, Scanner s) {
        if (inputCommand.equals("s")) {
            System.out.println(tree);
        } else if (inputCommand.equals("r")) {
            System.out.println("Total Nodes: " + tree.size);
            System.out.println("Min Depth: " + tree.minDepth());
            System.out.println("Max Depth: " + tree.maxDepth());
            System.out.println();
        } else if (inputCommand.equals("i")) {
            tree.insert(s.next());
        } else if (inputCommand.equals("d")) {
            tree.delete(s.next());
        } else if (inputCommand.equals("f")) {
            String word = s.next();
            System.out.print("Frequency of " + word + ": ");
            tree.reportFrequency(word);
            System.out.println();
        } else {
            System.err.println("COMMAND NOT VALID!");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        if (args[0].equals("-1")) new Trees(1, args[1], args[2]);
        else                      new Trees(2, args[1], args[2]);
    }

}
