/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int preOrderSolve(TreeNode* root, int total){
        if(!root) return 0;
        total = total*10 + root->val;
        
        if(!root->left && !root->right) return total;
        
        return preOrderSolve(root->left, total) + preOrderSolve(root->right, total);;
    }
    int sumNumbers(TreeNode* root) {
        
        return preOrderSolve(root, 0);
    }
};