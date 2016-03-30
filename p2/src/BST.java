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

    public MyTreeNode insert (String test) {
        MyTreeNode node = root;
        MyTreeNode newNode;
        if (size == 0) {
            newNode = new MyTreeNode(test, null, 0);
            this.root = newNode;
            size++;
            return newNode;
        }

        size++;
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
        return null;
    }

    public void delete(String text) {
        MyTreeNode temp = findNode(text);
        if (temp == null) {
            System.out.println("NODE NOT FOUND!");
            return;
        }
        if (temp.getFrequency() > 1) {
            temp.decrement();
            return;
        }
        temp = swapToLeaf(temp);
        prune(temp);
        size--;
    }

    public MyTreeNode swapToLeaf(MyTreeNode n) {
        MyTreeNode p = n.getParent();
        if (n.getLC() == null && n.getRC() == null) {
            // Leaf node
            return n;
        }

        if (n.getLC() != null) {
            MyTreeNode predecessor = null;
            // Left subtree is available
            predecessor = findPredecessor(n);
            n.setValue(predecessor.getValue());
            n.setFrequency(predecessor.getFrequency());
            return predecessor;
        } else {
            // No left subtree, use right child
            if (n.isRoot())
                this.root = n.getRC();
            else if (n.isLC())
                p.setLC(n.getRC());
            else
                p.setRC(n.getLC());
            return n.getRC();
        }
    }

    public void prune(MyTreeNode node) {
        if (node.isLC()) {
            node.getParent().setLC(null);
        } else {
            node.getParent().setRC(null);
        }
    }

    private MyTreeNode findPredecessor(MyTreeNode node) {
        MyTreeNode temp = node;
        temp = temp.getLC();
        while (temp.getRC() != null)
            temp = temp.getRC();
        MyTreeNode p = temp.getParent();
        if (temp.isLC()) {
            p.setLC(temp.getLC());
        }
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

    public MyTreeNode findNode(String text) {
        MyTreeNode temp = root;
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
        return temp;
    }

    public void reportFrequency(String text) {
        System.out.println(findNode(text).getFrequency());
    }

    public void levelOrderTraversal(MyTreeNode startNode) {
//        if (isEmpty()) {
//            System.out.println("THIS TREE IS EMPTY!");
//            return;
//        }
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

    public boolean isEmpty() {
        if (size == 0)
            return true;
        else
            return false;
    }

    @Override
    public String toString() {

        return "BST{}";
    }
}

