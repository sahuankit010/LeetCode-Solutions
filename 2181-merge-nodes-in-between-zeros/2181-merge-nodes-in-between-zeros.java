/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        // Initialize a dummy node to build the result list
        ListNode dummy = new ListNode(0);
        ListNode current = dummy; // This will be used to build the new list
        
        ListNode temp = head.next; // Start from the first node after the initial 0
        int sum = 0; // Variable to hold the sum of values between zeros
        
        while (temp != null) {
            if (temp.val != 0) {
                sum += temp.val; // Add the value to the sum
            } else {
                // We hit a 0, which means we have completed a segment
                current.next = new ListNode(sum); // Create a new node with the sum
                current = current.next; // Move the current pointer to this new node
                sum = 0; // Reset the sum for the next segment
            }
            temp = temp.next; // Move to the next node
        }
        
        // Return the next node of the dummy node which is the head of the new list
        return dummy.next;
    }
}
