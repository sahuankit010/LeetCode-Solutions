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
    void inOrder(TreeNode* root, unordered_set<int> &hash){
        if(!root) return;
        hash.insert(root->val);
        inOrder(root->left, hash);
        inOrder(root->right, hash);
    }
    bool isUnivalTree(TreeNode* root) {
        unordered_set<int> hash;
        inOrder(root, hash);
        return hash.size()==1;
    }
};