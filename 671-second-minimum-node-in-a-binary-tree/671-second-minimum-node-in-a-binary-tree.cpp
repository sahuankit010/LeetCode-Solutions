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
    
    int print2largest(vector<int>v){
    int i, first, second;
 
    /* There should be atleast two elements */
    if (v.size() < 2) {
        return -1;
    }
 
    first = second = INT_MAX;
    for (i = 0; i < v.size(); i++) {
        /* If current element is greater than first
           then update both first and second */
        if (v[i] < first) {
            second = first;
            first = v[i];
        }
 
        /* If arr[i] is in between first and
           second then update second  */
        else if (v[i] < second && v[i] != first)
            second = v[i];
    }
    if (second == INT_MAX)
        return -1;
    else
        return second;
}
public:
    int findSecondMinimumValue(TreeNode* root) {
        // Base Case
    if (root == NULL)
        return -1;
 
    // Create an empty queue for level order traversal
    queue<TreeNode*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
    vector<int>v;
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        TreeNode* node = q.front();
        v.push_back(node->val);
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
        }
        sort(v.begin(),v.end());
        set<int>s(v.begin(),v.end());
        if(s.size()==1) return -1;
        int i=1;
        int a=v[0];
        while(i<v.size() and v[i]==a) i++;
        if(i==v.size()) return -1;
        return v[i];
    }
};