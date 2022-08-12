/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int countList(ListNode *head){
        ListNode *curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
    
    ListNode *intersection(int d, ListNode *head1, ListNode *head2){
        
        ListNode *current1 = head1, *current2 = head2;
        
        for(int i=0;i<d;i++){
            if(current1==NULL) return NULL;
            current1=current1->next;
        }
        
        while(current1!=NULL && current2!=NULL){
            if(current1==current2) return current1;
            current1=current1->next;
            current2=current2->next;
        }
        
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int c1 = countList(headA), c2 = countList(headB);
        
        if(c1-c2>0){
            int d = c1-c2;
            return intersection(d,headA, headB);
        } else{
            int d = c2-c1;
            return intersection(d, headB, headA);
        }
    }
};