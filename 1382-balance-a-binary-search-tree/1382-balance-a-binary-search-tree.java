/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> array = new ArrayList<>();
        inorder(root, array);
        
        TreeNode head = rec(array, 0, array.size()-1);

        return head;
    }

    private void inorder(TreeNode root, List<Integer> array){

        if(root == null) return;

        inorder(root.left, array);
        array.add(root.val);
        inorder(root.right, array);
    }

    private TreeNode rec(List<Integer> nums, int low, int high){

        if(low > high) return null;

        int mid = low + (high-low)/2 ;

        TreeNode node = new TreeNode(nums.get(mid));

        node.left = rec(nums, low, mid-1);
        node.right = rec(nums, mid+1, high);

        return node;
    }
}