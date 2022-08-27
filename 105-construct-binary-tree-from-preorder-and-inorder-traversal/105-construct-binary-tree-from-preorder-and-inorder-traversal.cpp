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
    int preIndex = 0;
    TreeNode* cTree(vector<int>in, vector<int>pre, int is, int ie){
        
        if(is>ie) return nullptr;
        
        TreeNode* root = new TreeNode(pre[preIndex++]);
        
        int inIndex;
        
        for(int i=is; i<=ie; i++)
            if(in[i]==root->val){
                inIndex = i;
                break;
            }
        
        root->left = cTree(in, pre, is, inIndex-1);
        root->right = cTree(in, pre, inIndex + 1, ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        TreeNode *root = cTree(in, pre, 0, n-1);
        return root;
    }
};