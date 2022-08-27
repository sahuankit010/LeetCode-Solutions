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
    
    void findLeaves(TreeNode* root, vector<int> &vec){
        if(!root) return;
        if(!root->left && !root->right) vec.push_back(root->val);
        findLeaves(root->left, vec);
        findLeaves(root->right, vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        findLeaves(root1, vec1);
        findLeaves(root2, vec2);
        
        return vec1 == vec2;
    }
};