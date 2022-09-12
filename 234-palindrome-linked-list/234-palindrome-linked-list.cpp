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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode * temp = head;
        while(temp){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        
        int l = 0, h = vec.size()-1;
        
        while(l<h){
            if(vec[l++]!=vec[h--]) return false;
        }
        return true;
    }
};