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
    // int height(TreeNode* root){
    //     if(!root) return 0;
    //     return 1 + max(height(root->left), height(root->right));
    // }
    // int inOrder(TreeNode* root,int h){
    //     if(!root) return 0;
    //     if(h==1) return root->val;
    //     return inOrder(root->left, h-1) + inOrder(root->right, h-1);
    // }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            int n = q.size();
            sum = 0; // re-initialize sum, if another level exists
            while(n--){
                TreeNode *node = q.front();q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                if(!node->right && !node->left) // if this is a leaf node
                    sum += node->val;
            }
        }
        return sum;
    }
};