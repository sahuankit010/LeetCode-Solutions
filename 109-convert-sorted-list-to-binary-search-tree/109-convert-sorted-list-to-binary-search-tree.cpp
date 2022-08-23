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
        
    TreeNode* sortedListToBST(ListNode* head) {
      if(head == NULL)
            return NULL;

        int count = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        
        if(count == 1){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        
        int n = count/2;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;
        
        while(n--){
            prev = curr;
            curr = next;
            next = next->next;
        }
        prev->next = NULL;
        curr->next = NULL;
        TreeNode* root = new TreeNode(curr->val);
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(next);
        
        return root;
    }
};