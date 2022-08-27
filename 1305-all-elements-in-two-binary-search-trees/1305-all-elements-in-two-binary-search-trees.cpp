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
        if(!root) return;
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        inOrder(root1, vec1);
        inOrder(root2, vec2);
        vector<int> ans;
        int i=0, j=0;
        int m = vec1.size(), n = vec2.size();
        while(i<m && j<n){
            if(vec1[i]<=vec2[j]) {
                ans.push_back(vec1[i++]);
            } else{
                ans.push_back(vec2[j++]);
            }
        }
        
        while(i<m) ans.push_back(vec1[i++]);
        while(j<n) ans.push_back(vec2[j++]);
        
        return ans;
    }
};