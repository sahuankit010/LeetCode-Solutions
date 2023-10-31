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

    long long postOrder(TreeNode* root, int &ans){
        if(root==nullptr) return 0;
        long long subSum = postOrder(root->left, ans) + postOrder(root->right, ans);
        if(subSum == root->val) ans++;
        return subSum += root->val;
        
    }
    int equalToDescendants(TreeNode* root) {
        
        int ans = 0;
        postOrder(root, ans);

        return ans;
    }
};