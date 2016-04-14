/**
 * Standard Queue class used in printing level order for Trees.
 * Each queue node will hold a tree node as its data.
 */

public class MyQueue {

    /**
     * Queue node holds the Tree Nodes
     */
    public class QueueNode {
        MyTreeNode value;
        QueueNode next;
        public QueueNode(MyTreeNode value) {
            next = null;
            this.value = value;
        }
    }

    QueueNode front;
    QueueNode back;
    int size;

    public MyQueue() {
        front = null;
        back  = null;
        size = 0;
    }

    public void add(MyTreeNode tn) {
        size++;
        QueueNode temp = new QueueNode(tn);
        if (front == null && back == null) {
            front = back = temp;
            return;
        }
        back.next = temp;
        back = temp;
    }

    public MyTreeNode remove() {
        MyTreeNode returnNode;
        if (front == null) {
            // Empty Queue
            return null;
        }
        size--;
        if (front == back) {
            returnNode = front.value;
            front = back = null;
        } else {
            returnNode = front.value;
            front = front.next;
        }
        return returnNode;
    }

    public boolean isEmpty() {
        if (size == 0) return true;
        else           return false;
    }
}
