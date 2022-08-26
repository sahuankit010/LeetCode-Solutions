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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        map<int,vector<int>>hm;
        queue<pair<TreeNode*,int>>q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            hm[hd].push_back(curr->val);
            if(curr->left)
                q.push({curr->left,hd-1});
            if(curr->right)
                q.push({curr->right,hd+1});
        }
        
        vector<vector<int>>ans;
        
        for(auto x: hm){
            vector<int> temp;
            for(int i=0; i<x.second.size();i++){
                temp.push_back(x.second[i]);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};