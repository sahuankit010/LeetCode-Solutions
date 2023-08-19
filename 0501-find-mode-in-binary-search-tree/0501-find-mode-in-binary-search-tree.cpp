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
    void inorder(TreeNode *root, unordered_map<int, int> &ans){
        if(root == nullptr) return;
        
        inorder(root->left, ans);
        
        ans[root->val]++;
        
        inorder(root->right, ans);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        inorder(root, map);
        
        int maxi = INT_MIN;
        cout<<map.size()<<endl;
        for(auto &a : map){
            cout<<a.first<<" "<<a.second<<endl;
            maxi = max(maxi, a.second);
        }
        
        vector<int>ans;
        
        for(auto &a : map){
            if(a.second == maxi)
                ans.push_back(a.first);
        }
        return ans;
    }
};