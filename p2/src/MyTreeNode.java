/**
 * Tree Node Class.
 * Contains the value of a read string, the
 * frequency of the string found in the file,
 * pointers to left and right children as well as parent,
 * and variables to help distinguish the node as a LC, RC, colored
 * black, and colored red.
 */
public class MyTreeNode {

    private int frequency;
    private String value;
    private MyTreeNode parent;
    private MyTreeNode LC;
    private MyTreeNode RC;

    // Helps in boolean methods
    private boolean black;
    private boolean red;
    private int id; // 0 for root, 1 for left, 2 for right

    /**
     * Default constructor, initializes variables.
     * @param value String that was read from file.
     * @param parent Parent of node.
     * @param id Root, LC, or RC.
     */
    public MyTreeNode(String value, MyTreeNode parent, int id) {
        this.value  = value;
        this.parent = parent;
        this.id     = id;
        frequency = 1;
        LC = null;
        RC = null;
        black = false;
        red = false;
    }

    public boolean isRoot() { return id == 0; }
    public boolean isLC() { return id == 1; }
    public boolean isRC() { return id == 2; }

    public void increment() { this.frequency++; }
    public void decrement() { this.frequency--; }

    public int getFrequency() { return frequency; }
    public void setFrequency(int frequency) { this.frequency = frequency; }

    public String getValue() { return value; }
    public void setValue(String value) { this.value = value; }

    public MyTreeNode getParent() { return parent; }
    public void setParent(MyTreeNode parent) { this.parent = parent; }

    public MyTreeNode getUncle() {
        if (parent.isLC())
            return parent.parent.RC;
        else
            return parent.parent.LC;
    }
    public MyTreeNode getSibling() {
        if (isLC())
            return parent.RC;
        else
            return parent.LC;
    }

    // Nephew and Niece used exclusively in RBT delete fix-up
    public MyTreeNode getNephew() {
        if (isLC())
            return getSibling().RC;
        else
            return getSibling().LC;
    }
    public MyTreeNode getNiece() {
        if (isLC())
            return getSibling().LC;
        else
            return getSibling().RC;
    }

    public MyTreeNode getLC() { return LC; }
    public void setLC(MyTreeNode LC) {
        this.LC = LC;
        if (this.LC != null)
            this.LC.setId(1);
    }
    public MyTreeNode getRC() { return RC; }
    public void setRC(MyTreeNode RC) {
        this.RC = RC;
        if (this.RC != null)
            this.RC.setId(2);
    }

    public void setId(int id) { this.id = id; }

    public void setBlack() { black = true; red = false; }
    public void setRed() { red = true; black = false; }

    public boolean isRed() { return red; }
    public boolean isBlack() { return black; }

    public boolean isLeaf() { return getLC() == null && getRC() == null; }

    public boolean isLinear() { return (parent.isRC() && isRC()) || (parent.isLC() && isLC()); }

    /**
     * String representation of a Tree Node.
     * @return Tree Node string.
     */
    @Override
    public String toString() {
        String redChar;
        if (isRed()) redChar = "*";
        else         redChar = "";

        String leafChar;
        if (isLeaf()) leafChar = "=";
        else          leafChar = "";

        String childChar;
        if (isRoot())    childChar = "X";
        else if (isRC()) childChar = "R";
        else             childChar = "L";

        if (parent != null)
            return leafChar + value + redChar + "(" + parent.value + ")" + frequency + childChar;
        else
            return leafChar + value + redChar + "(" + value + ")" + frequency + childChar;
    }
}


