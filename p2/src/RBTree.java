/**
 * Red-Black Tree Class.
 * Inherits from the BST class. Delete and
 * insert methods are overridden due to the needed
 * addition of the helpher methods insertFixUp and
 * deleteFixUp
 */
public class RBTree extends BST {

    public RBTree() { super(); }

    /**
     * Insert a word into the RBT tree.
     * Set this new node to red and then preform
     * insertFixUp to maintain RBT form and coloring.
     * @param text Word to be inserted into tree.
     * @return null.
     */
    public MyTreeNode insert(String text) {
        MyTreeNode n = super.insert(text);
        if (n != null) {
            n.setRed();
            insertFixUp(n);
        }
        return null;
    }

    /**
     * The only difference between this RBT delete and a standard
     * delete from BST is the addition of the deleteFixUp in order
     * to maintain the RBT coloring and form.
     * @param text The word to be deleted from the tree.
     */
    public void delete(String text) {
        if (isEmpty()) {
            System.err.println("THIS TREE IS EMPTY");
            return;
        }
        MyTreeNode temp = findNode(text);
        MyTreeNode leaf;
        if (temp == null) {
            System.err.println("TRYING TO DELETE A NODE THAT DOES NOT EXIST");
            return;
        }
        if (temp.getFrequency() > 1) {
            temp.decrement();
            return;
        }
        leaf = swapToLeaf(temp);
        deleteFixUp(leaf);
        prune(leaf);
        size--;
    }

    /**
     * Java implementation of Dr. Lusth's pseudocode
     * for fixing coloring and shape of tree after insertion.
     * @param n
     */
    private void insertFixUp(MyTreeNode n) {
        while (true) {
            if (n.isRoot()) break;
            if (n.getParent().isBlack()) break;
            if (n.getUncle() != null && n.getUncle().isRed()) {
                n.getParent().setBlack();
                n.getUncle().setBlack();
                n.getParent().getParent().setRed();
                n = n.getParent().getParent();
            }
            else {
                // uncle must be black
                if (!n.isLinear()) {
                    MyTreeNode tempN = n;
                    MyTreeNode tempParent = n.getParent();
                    rotate(n);
                    n = tempParent;
                    n.setParent(tempN);
                }

                n.getParent().setBlack();
                if (n.getParent().getParent() != null) {
                    n.getParent().getParent().setRed();
                }

                rotate(n.getParent());
                break;
            }
        }
        root.setBlack();
    }

    private void deleteFixUp(MyTreeNode n) {
        while (true) {
            if (n.isRoot()) break;
            if (n.isRed()) break;
            if (n.getSibling().isRed()) {
                n.getParent().setRed();
                n.getSibling().setBlack();
                rotate(n.getSibling());
                // should have black sibling now
            }
            else if (n.getNephew()!=null && n.getNephew().isRed()) {
                if (n.getParent().isRed()) n.getSibling().setRed();
                else n.getSibling().setBlack();
                n.getParent().setBlack();
                n.getNephew().setBlack();
                rotate(n.getSibling());
                n = root;
                // subtree and tree is BH balanced
            }
            else if (n.getNiece() != null && n.getNiece().isRed()) {
                // nephew must be black
                n.getNiece().setBlack();
                n.getSibling().setRed();
                rotate(n.getNiece());
                // should have red nephew now
            }
            else { // sibling, niece, and nephew must be black
                n.getSibling().setRed();
                n = n.getParent();
                // this subtree is BH balanced, but tree is not
            }
        }
        n.setBlack();
    }

    private void rotate(MyTreeNode n) {
        if (n.isLC()) { // right rotate
            right(n);
        } else {        // left rotate
            left(n);
        }
    }

    private void left(MyTreeNode n) {
        MyTreeNode parent = n.getParent();
        parent.setRC(n.getLC());
        if (n.getLC() != null) {
            n.getLC().setParent(parent);
        }
        n.setParent(parent.getParent());
        n.setLC(parent);

        if (parent.getParent() == null) setRoot(n);
        else {
            if (parent == parent.getParent().getLC()) {
                parent.getParent().setLC(n);
            } else {
                parent.getParent().setRC(n);
            }
        }
        n.setLC(parent);
        parent.setParent(n);
    }

    private void right(MyTreeNode n) {
        MyTreeNode parent = n.getParent();
        parent.setLC(n.getRC());
        if (n.getRC() != null) {
            n.getRC().setParent(parent);
        }
        n.setParent(parent.getParent());
        n.setRC(parent);

        if (parent.getParent() == null) setRoot(n);
        else {
            if (parent == parent.getParent().getRC()) {
                parent.getParent().setRC(n);
            } else {
                parent.getParent().setLC(n);
            }
        }
        n.setRC(parent);
        parent.setParent(n);
    }
}
