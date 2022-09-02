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
    void inOrder(TreeNode* root, unordered_map<int,int> &hm){
        if(!root) return;
        inOrder(root->left,hm);
        hm[root->val]++;
        inOrder(root->right,hm);
    }
    
    bool static cmp(pair<int,int> p1, pair<int,int> p2){
        return p1.second>=p2.second;
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> hm;
        inOrder(root, hm);
        vector<pair<int,int>> vec;
        for(auto x: hm){
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end(), cmp);
        vector<int> res;
        int c = 1;
        for(int i=0;i<vec.size();i++){
            if(vec[i].second>=c){
                res.push_back(vec[i].first);
                c =vec[i].second;
            }
        }
        return res;
    }
};