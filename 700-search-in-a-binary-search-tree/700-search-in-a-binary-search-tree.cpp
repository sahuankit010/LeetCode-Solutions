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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val == val){
                return node;
            }
            q.pop(); 
            if (node->left) q.push(node->left); 
            if (node->right) q.push(node->right); 
        }
        return NULL;
    }
};