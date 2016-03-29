/**
 * Tree Node Class
 */

public class MyTreeNode {

    private int frequency = 1;
    private String value = null;
    private MyTreeNode parent = null;
    private MyTreeNode LC = null;
    private MyTreeNode RC = null;
    private boolean black = false;
    private boolean red   = false;
    private int id; // 0 for root, 1 for left, 2 for right
    private String redChar;

    public MyTreeNode(String value, MyTreeNode parent, int id) {
        this.value  = value;
        this.parent = parent;
        this.id     = id;
    }

    public boolean isRoot() { if (id == 0) return true; else return false; }
    public boolean isLC() { if (id == 1) return true; else return false; }
    public boolean isRC() { if (id == 2) return true; else return false; }

    public void increment() {
        this.frequency++;
    }
    public void decrement() { this.frequency--; }

    public int getFrequency() {
        return frequency;
    }

    public void setFrequency(int frequency) {
        this.frequency = frequency;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public MyTreeNode getParent() {
        return parent;
    }

    public void setParent(MyTreeNode parent) {
        this.parent = parent;
    }

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

    public MyTreeNode getNephew() {
        if (isLC()) {
            return getSibling().RC;
        } else {
            return getSibling().LC;
        }
    }

    public MyTreeNode getNiece() {
        if (isLC()) {
            return getSibling().LC;
        } else {
            return getSibling().RC;
        }
    }

    public MyTreeNode getLC() {
        return LC;
    }

    public void setLC(MyTreeNode LC) {
        this.LC = LC;
        if (this.LC != null)
            this.LC.setId(1);
    }

    public MyTreeNode getRC() {
        return RC;
    }

    public void setRC(MyTreeNode RC) {
        this.RC = RC;
        if (this.RC != null)
            this.RC.setId(2);
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setBlack() { black = true; red = false; }
    public void setRed() { red = true; black = false; }

    public boolean isRed() { if (red) return true; else return false; }
    public boolean isBlack() { if (black) return true; else return false; }

    public boolean isLinear() {
        if ((parent.isRC() && isRC()) || (parent.isLC() && isLC()))
            return true;
        else
            return false;
    }

    @Override
    public String toString() {
        if (isRed()) {
            redChar = "*";
        } else {
            redChar = "";
        }
        if (id == 0)
            return value + redChar + "(" + value + ")" + frequency + "X";
        else {
            if (id == 1) {
                return value + redChar + "(" + parent.value + parent.redChar + ")" + frequency + "L";
            }
            else
                return value + redChar + "(" + parent.value + parent.redChar + ")" + frequency +"R";
        }
    }
}
