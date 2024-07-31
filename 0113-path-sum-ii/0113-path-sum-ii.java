class Solution {
    // Declare temporary list to store current path and list to store all valid paths
    List<Integer> temp;
    List<List<Integer>> ans;

    // Constructor to initialize the lists
    Solution() {
        temp = new ArrayList<>();
        ans = new ArrayList<>();
    }

    // Main function to find all paths with the given target sum
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        dfs(root, targetSum);  // Call depth-first search helper function
        return ans;            // Return the list of valid paths
    }

    // Helper function to perform depth-first search
    private void dfs(TreeNode root, int targetSum) {
        // Base case: if current node is null, return
        if (root == null) {
            return;
        }

        // Add current node's value to the temporary path list
        temp.add(root.val);

        // Check if current node is a leaf and its value equals the remaining target sum
        if (root.val == targetSum && root.left == null && root.right == null) {
            ans.add(new ArrayList<>(temp));  // Add a copy of the current path to the answer list
        }

        // Recursively call dfs for left and right children with updated target sum
        dfs(root.left, targetSum - root.val);
        dfs(root.right, targetSum - root.val);

        // Backtrack: remove the last node's value from the temporary path list
        temp.remove(temp.size() - 1);
    }
}
