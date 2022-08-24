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
    
    void inOrder(TreeNode* root,vector<int> &vec){
        if(root==nullptr) return;
        else{
            inOrder(root->left, vec);
            vec.push_back(root->val);
            inOrder(root->right, vec);
        }
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        
        int ans = vec[1]-vec[0];
        
        for(int i=1;i<vec.size()-1;i++){
            ans=min(ans, vec[i+1]-vec[i]);
        }
        return ans;
    }
};