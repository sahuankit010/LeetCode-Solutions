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
    void inOrder(TreeNode* root, vector<int> &vec){
        if(root==nullptr) return;
        inOrder(root->left,vec);
        vec.push_back(root->val);
        inOrder(root->right,vec);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>vec;
        inOrder(root,vec);
        
        int l=0, r= vec.size()-1;
        
        while(l<r){
            int sum = vec[l] + vec[r];
            
            if(sum == k) return true;
            
            else if (sum>k) r--;
            
            else l++;
        }
        
        return false;
    }
};