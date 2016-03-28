import java.util.LinkedList;
import java.util.Queue;

/**
 * Binary Search Tree Class
 */
public class BST {
    private int size = 0;
    private MyTreeNode root;

    public BST() {
    }

    public MyTreeNode insert(MyTreeNode node, String test) {
        MyTreeNode newNode;
        if (size == 0) {
            newNode = new MyTreeNode(test, null, 0);
            this.root = newNode;
            size++;
            return newNode;
        }

        while (node != null) {
            if (test.compareTo(node.getValue()) == 0) {
                node.increment();
                return null;
            } else if (test.compareTo(node.getValue()) >= 1) {
                if (node.getRC() == null) {
                    newNode = new MyTreeNode(test, node, 2);
                    node.setRC(newNode);
                    return newNode;
                } else {
                    node = node.getRC();
                }
            } else {
                if (node.getLC() == null) {
                    newNode = new MyTreeNode(test, node, 1);
                    node.setLC(newNode);
                    return newNode;
                } else {
                    node = node.getLC();
                }
            }
        }
        size++;
        return null;
    }

    public void delete(String text) {
        MyTreeNode temp = this.root;
        while (temp != null) {
            if (text.compareTo(temp.getValue()) == 0)
                break;
            else if (text.compareTo(temp.getValue()) >= 1) {
                temp = temp.getRC();
            }
            else {
                temp = temp.getLC();
            }
        }

        if (temp.getFrequency() > 1) {
            temp.decrement();
            return;
        }


        MyTreeNode p = temp.getParent();
        if (temp.getLC() == null && temp.getRC() == null) {
            // Leaf node
            if (temp.getId() == 1)
                p.setLC(null);
            else
                p.setRC(null);
            return;
        }


        if (temp.getLC() != null) {
            // Left subtree is available
            MyTreeNode predecessor = findPredecessor(temp);
            temp.setValue(predecessor.getValue());
            temp.setFrequency(predecessor.getFrequency());
        } else {
            // No left subtree, use right child
            if (temp.isRoot())
                this.root = temp.getRC();
            else if (temp.isLC())
                p.setLC(temp.getRC());
            else
                p.setRC(temp.getLC());
        }
        size--;
    }

    private MyTreeNode findPredecessor(MyTreeNode node) {
        MyTreeNode temp = node;
        temp = temp.getLC();
        while (temp.getRC() != null)
            temp = temp.getRC();
        MyTreeNode p = temp.getParent();
        if (temp.isLC())
            p.setLC(null);
        else
            p.setRC(null);
        return temp;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public MyTreeNode getRoot() {
        return root;
    }

    public void setRoot(MyTreeNode root) {
        this.root = root;
        this.root.setId(0);
    }

    public static void levelOrderTraversal(MyTreeNode startNode) {
        Queue<MyTreeNode> queue=new LinkedList<MyTreeNode>();
        queue.add(startNode);
        int nodesInCurrentLevel = 1;
        int nodesInNextLevel = 0;
        int level = 1;
        String levelBuilder = "";
        while (!queue.isEmpty()) {
            MyTreeNode tempNode=queue.peek();
            queue.remove();
            nodesInCurrentLevel--;
            if (tempNode != null) {
                levelBuilder = levelBuilder + tempNode + " ";
                queue.add(tempNode.getLC());
                queue.add(tempNode.getRC());
                nodesInNextLevel += 2;
            }
            if (nodesInCurrentLevel == 0) {
                String print = level + ": " + levelBuilder;
                levelBuilder = "";
                System.out.print(print);
                System.out.println();
                level++;
                nodesInCurrentLevel = nodesInNextLevel;
                nodesInNextLevel = 0;
            }
        }
    }

    @Override
    public String toString() {

        return "BST{}";
    }
}

