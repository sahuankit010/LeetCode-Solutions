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
    
    bool isLeaf(TreeNode *root){
        return (!root->left && !root->right);
    }
    
    void addLeft(TreeNode *root, vector<int>&ans){
        TreeNode *curr = root;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->val);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addRight(TreeNode *root, vector<int>&ans){
        vector<int>temp;
        
        TreeNode *curr = root;
        
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->val);
            if(curr->right) curr= curr->right;
            else curr = curr->left;
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
    
    void addLeaves(TreeNode *root, vector<int>&ans){
        
        if(isLeaf(root)){
            ans.push_back(root->val);
            return;
        }
        
        if(root->left) addLeaves(root->left, ans);
        if(root->right) addLeaves(root->right, ans);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        if(!isLeaf(root)) ans.push_back(root->val);
        addLeft(root->left, ans);
        addLeaves(root, ans);
        addRight(root->right, ans);
        return ans;
    }
};