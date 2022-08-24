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
    // vector<int>curr;
    void preOrder(TreeNode* root, int target, vector<vector<int>> &ans, vector<int> curr){
        if(!root) return;
        
        if(target==root->val && !root->left && !root->right) {
            curr.push_back(root->val);
            ans.push_back(curr);
            return;
        }
        curr.push_back(root->val);
        preOrder(root->left, target-root->val, ans, curr);
        preOrder(root->right, target-root->val, ans, curr);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        preOrder(root, targetSum, ans,curr);
        return ans;
    }
};