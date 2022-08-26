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
    void inOrder(TreeNode* root, vector<TreeNode*> &ans){
        if(!root) return;
        inOrder(root->left, ans);
        ans.push_back(root);
        inOrder(root->right, ans);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> ans;
        inOrder(root, ans);
        int i;
        for(i=0;i<ans.size();i++){
            if(ans[i]->val==p->val) break;
        }
        if(i!=ans.size()-1) {
            i++;
            return ans[i];
        }
        return nullptr;
    }
};