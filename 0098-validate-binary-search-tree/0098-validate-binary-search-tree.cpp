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
    
    bool validateBST(TreeNode* root, TreeNode* low, TreeNode* high){
        if(root == nullptr) return true;
        if((low != nullptr && root->val <= low->val) || (high != nullptr && root->val >= high->val)) return false;
        
        return validateBST(root->left, low, root) && validateBST(root->right, root, high);
    }

    bool isValidBST(TreeNode* root) {
        return validateBST(root, nullptr, nullptr);
    }
};