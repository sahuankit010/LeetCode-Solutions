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
    void inorder(TreeNode* root,vector<int>&v){
		    if(root!=nullptr){
			    inorder(root->left,v);
			    v.push_back(root->val);
			    inorder(root->right,v);
		    }
		    return;
	    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int>v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        int l=0, r = v2.size()-1;
        
        while(l<v1.size() && r>=0){
            int sum = v1[l]+v2[r];
            if(sum==target) return true;
            else if(sum>target) r--;
            else l++;
        }
        return false;
    }
};