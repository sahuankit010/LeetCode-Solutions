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
    
    void inOrder(TreeNode* root, double target, pair<int, double> &val){
        if(!root) return;
        if(val.second>abs(target-root->val)){
            val.second = abs(target-root->val);
            val.first = root->val;
        }
        
        inOrder(root->left, target, val);
        inOrder(root->right, target, val);
    }
    int closestValue(TreeNode* root, double target) {
        pair<int, double> val;
        val.second = DBL_MAX;
        inOrder(root, target, val);
        return val.first;
    }
};