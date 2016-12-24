/* Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
*/
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
    ListNode* oddEvenList(ListNode* head) {
        if((head == NULL) || (head -> next == NULL) || (head -> next -> next == NULL)) return head;
        
        ListNode* oddTail = head;
        ListNode* evenTail = head -> next;
        ListNode* cur;
        
        while((evenTail != NULL) && (evenTail->next != NULL)) {
            
            cur = evenTail -> next;
            
            evenTail -> next = cur -> next;
            cur -> next = oddTail -> next;
            oddTail -> next = cur;
                
            evenTail = evenTail -> next;
            oddTail = oddTail -> next;
        }
        
        return head;
    }
};
