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
    void inorder(TreeNode* root, vector<int> &vec){
        if(!root) return;
        if(!root->left and !root->right) vec.push_back(root->val);
        inorder(root->left, vec);
        inorder(root->right, vec);
    }
    
    void show(vector<int> vec){
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        inorder(root1, vec1);
        inorder(root2, vec2);
        // show(vec1);
        // cout<<endl;
        if(vec1.size()!=vec2.size()) return false;
        for(int i=0; i<vec1.size(); i++){
            if(vec1[i]!=vec2[i]) return false;
        }
        return true;
    }
};