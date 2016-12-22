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
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        
        ListNode* pre = node;
        ListNode* next = node -> next;
        while(next != NULL) {
            node -> val = next -> val;
            pre = node;
            node = next;
            next = node -> next;
        }
        
        delete(node);
        pre->next = NULL;
        return;
    }
};
