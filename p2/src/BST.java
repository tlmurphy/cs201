/**
 * Binary Search Tree Class.
 * Contains standard methods for a BST:
 * insert and delete. Also has many helper methods
 * to help in insertions, deletions, and printing the level
 * order.
 */
public class BST {

    int size;
    MyTreeNode root;

    /**
     * Default constructor for BST.
     * Initialize variables.
     */
    public BST() {
        size = 0;
        root = null;
    }

    /**
     * Insert a new node holding the value of the string
     * that was just read. Sets this new node to root if
     * the tree is empty. Else, find the appropriate place
     * for the node and increment the size.
     * @param text Word to be inserted into tree.
     * @return The new node that was just inserted.
     */
    public MyTreeNode insert (String text) {
        MyTreeNode node = root;
        MyTreeNode newNode;
        if (size == 0) {
            newNode = new MyTreeNode(text, null, 0);
            this.root = newNode;
            size++;
            return newNode;
        }

        while (node != null) {
            if (text.compareTo(node.getValue()) == 0) {
                node.increment();
                return null;
            } else if (text.compareTo(node.getValue()) >= 1) { // Search right subtree
                if (node.getRC() == null) {
                    newNode = new MyTreeNode(text, node, 2);
                    node.setRC(newNode);
                    size++;
                    return newNode;
                } else {
                    node = node.getRC();
                }
            } else {
                if (node.getLC() == null) {                    // Search left subtree
                    newNode = new MyTreeNode(text, node, 1);
                    node.setLC(newNode);
                    size++;
                    return newNode;
                } else {
                    node = node.getLC();
                }
            }
        }
        return null;
    }

    /**
     * Find a value in the tree and delete it.
     * First search for the node to be deleted, once
     * found, swap it with children until it is a leaf.
     * Once the node to be deleted is a leaf, it can now be pruned
     * from the tree.
     * If the tree is empty, or the word cannot be found in the tree,
     * an error message is printed.
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
        prune(leaf);
        size--;
    }

    /**
     * Swap a node with its children until it becomes
     * a leaf node. Uses find predecessor until a left child
     * does not exist, then uses find successor to find the swap
     * node.
     * @param n The node to be swapped until it is a leaf.
     * @return The final leaf node.
     */
    public MyTreeNode swapToLeaf(MyTreeNode n) {
        MyTreeNode swp;
        if (n.isLeaf()) return n;

        // Find a node to swap with
        if (n.getLC() != null)
            swp = findPredecessor(n);
        else
            swp = findSuccessor(n);

        swap(n, swp);
        return swapToLeaf(swp);
    }

    /**
     * Swap two nodes (only their values and frequencies).
     * @param n First node to swap.
     * @param swp Second node to swap.
     */
    private void swap(MyTreeNode n, MyTreeNode swp) {
        int tempF = n.getFrequency();
        String tempS = n.getValue();
        n.setFrequency(swp.getFrequency());
        n.setValue(swp.getValue());
        swp.setFrequency(tempF);
        swp.setValue(tempS);
    }

    /**
     * Remove a leaf node from the tree.
     * @param node Leaf node to be removed.
     */
    public void prune(MyTreeNode node) {
        if (node.isLC()) {
            node.getParent().setLC(null);
        } else {
            node.getParent().setRC(null);
        }
    }

    private MyTreeNode findSuccessor(MyTreeNode node) {
        MyTreeNode temp = node;
        temp = temp.getRC();
        while (temp.getLC() != null)
            temp = temp.getLC();
        return temp;
    }

    private MyTreeNode findPredecessor(MyTreeNode node) {
        MyTreeNode temp = node;
        temp = temp.getLC();
        while (temp.getRC() != null)
            temp = temp.getRC();
        return temp;
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
            else if (text.compareTo(temp.getValue()) >= 1)
                temp = temp.getRC();
            else
                temp = temp.getLC();
        }
        return temp;
    }

    public void reportFrequency(String text) {
        MyTreeNode node = findNode(text);
        if (node != null) {
            System.out.println(node.getFrequency());
        } else {
            System.out.println(0);
        }
    }

    /**
     * Used in printing the level order representation
     * of the tree. Uses two queues in order to keep track
     * of the current and next level.
     * @return Final level order representation of tree.
     */
    public String levelOrderTraversal() {
        if (isEmpty()) {
            return "THIS TREE IS EMPTY";
        }
        MyQueue currentLevel = new MyQueue();
        MyQueue nextLevel = new MyQueue();
        String builder = "";
        String builderHelper = "";
        currentLevel.add(root);
        int level = 1;
        while (!currentLevel.isEmpty()) {
            MyTreeNode temp = currentLevel.remove();
            builderHelper = builderHelper + temp + " ";
            if (temp.getLC() != null)
                nextLevel.add(temp.getLC());
            if (temp.getRC() != null)
                nextLevel.add(temp.getRC());
            if (currentLevel.isEmpty()) {
                builder = builder + level + ": " + builderHelper + "\n";
                builderHelper = "";
                level++;
                currentLevel = nextLevel;
                nextLevel = new MyQueue();
            }
        }
        return builder;
    }

    public int minDepth() {
        if (isEmpty()) {
            return 0;
        }
        MyQueue currentLevel = new MyQueue();
        MyQueue nextLevel = new MyQueue();
        currentLevel.add(root);
        int level = 1;
        while (!currentLevel.isEmpty()) {
            MyTreeNode temp = currentLevel.remove();
            if (temp.isLeaf()) {
                return level;
            }
            if (temp.getLC() != null)
                nextLevel.add(temp.getLC());
            if (temp.getRC() != null)
                nextLevel.add(temp.getRC());
            if (currentLevel.isEmpty()) {
                level++;
                currentLevel = nextLevel;
                nextLevel = new MyQueue();
            }
        }
        return level - 1;
    }

    public int maxDepth() {
        if (isEmpty()) {
            return 0;
        }
        MyQueue currentLevel = new MyQueue();
        MyQueue nextLevel = new MyQueue();
        currentLevel.add(root);
        int level = 1;
        while (!currentLevel.isEmpty()) {
            MyTreeNode temp = currentLevel.remove();
            if (temp.getLC() != null)
                nextLevel.add(temp.getLC());
            if (temp.getRC() != null)
                nextLevel.add(temp.getRC());
            if (currentLevel.isEmpty()) {
                level++;
                currentLevel = nextLevel;
                nextLevel = new MyQueue();
            }
        }
        return level - 1;
    }


    public boolean isEmpty() { return size == 0; }

    @Override
    public String toString() { return levelOrderTraversal(); }
}

