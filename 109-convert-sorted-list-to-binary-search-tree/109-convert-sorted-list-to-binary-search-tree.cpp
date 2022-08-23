/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
      
    TreeNode* treeBuiler(vector<int> &vec, int left, int right){
        
        if(left>right) return nullptr;
        
        int mid = left + (right-left)/2;
        TreeNode* temp = new TreeNode(vec[mid]);
        temp->left = treeBuiler(vec,left, mid-1);
        temp->right = treeBuiler(vec, mid+1, right);
        return temp;                         
    }
    
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         return treeBuiler(nums, 0, nums.size()-1);
//     }
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int>nums;
        
        if(head == nullptr) return nullptr;
        
        else{
            while(head!=nullptr){
                nums.push_back(head->val);
                head = head->next;
            }
        }
        return treeBuiler(nums, 0, nums.size()-1);
    }
};