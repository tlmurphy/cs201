/**
 * Created by Trevor on 3/27/2016.
 */
public class RBTree extends BST {

    public RBTree() {
    }

    public void insertRBT(MyTreeNode node, String text) {
        MyTreeNode n = super.insert(node, text);
        if (n != null) {
            n.setRed();
            insertFixUp(n);
        }
    }

    public void deleteRBT(String text) {
        super.delete(text);
    }

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
//                  rotate parent to grandparent
                break;
            }
        }
        getRoot().setBlack();
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
            else if (n.getNephew().isRed()) {
                if (n.getParent().isRed()) n.getSibling().setRed();
                else n.getSibling().setBlack();
                n.getParent().setBlack();
                n.getNephew().setBlack();
                rotate(n.getSibling());
                n = getRoot();
                // subtree and tree is BH balanced
            }
            else if (n.getNiece().isRed()) {
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
