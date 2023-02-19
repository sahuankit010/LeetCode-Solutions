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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        int n=1;
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            while(size--){
                TreeNode *temp = q.front();
                vec.push_back(temp->val);
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            if(n%2 == 0) reverse(begin(vec), end(vec));
            ans.push_back(vec);
            n++;
        }
        return ans;
    }
};