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
    void leftLeafSum(TreeNode* root, int &sum){
        if(!root) return;
        if(root->left)
            if(!root->left->left && !root->left->right) sum+= root->left->val;
        leftLeafSum(root->left, sum);
        leftLeafSum(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        leftLeafSum(root, sum);
        return sum;
    }
};