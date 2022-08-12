/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool findPath (TreeNode* root,vector<TreeNode*> &path, TreeNode* k){
        if(root==NULL) return false;
        
        path.push_back(root);
        if(root->val == k->val) return true;
        if((root->left && findPath(root->left, path, k)) ||
          (root->right && findPath(root->right, path, k)))
            return true;
        path.pop_back();
        
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1,path2;
        
        if(!findPath(root,path1,p) || !findPath(root,path2,q)) return NULL;
        int i;
        for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i]->val != path2[i]->val)
            break;

        return path1[i - 1];
        
    }
};