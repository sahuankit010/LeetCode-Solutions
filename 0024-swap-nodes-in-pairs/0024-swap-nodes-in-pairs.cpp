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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       // changing pointers
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *curr1 = head;
        ListNode  *curr2 = head->next;
        ListNode  *curr3 = head->next->next;
        
        curr1->next = swapPairs(curr3);
        curr2->next = curr1;
        
        return curr2;
        
    }
};