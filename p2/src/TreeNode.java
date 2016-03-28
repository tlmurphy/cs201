public class TreeNode {

    private int value;
    private TreeNode parent;
    private TreeNode LC;
    private TreeNode RC;

	/**
	* Default TreeNode constructor
	*/
	public TreeNode(int value, TreeNode parent) {
		this.value  = value;
        this.parent = parent;
        this.LC     = null;
        this.RC     = null;
	}
}
