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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return {};
        vector<int> temp;
        
        ListNode *curr = head;
        
        while(curr!=nullptr){
            temp.push_back(curr->val);
            if(curr->next && curr->next->next!=nullptr)
                curr = curr->next->next;
            else break;
        }
        curr=head;
        curr = curr->next;
        while(curr!=nullptr){
            temp.push_back(curr->val);
            if(curr->next && curr->next->next!=nullptr)
                curr = curr->next->next;
            else break;
        }
        
        curr = head;
        ListNode *res = curr;
        
        for(int x: temp){
            curr->val = x;
            curr = curr->next;
        }
        return res;
    }
};