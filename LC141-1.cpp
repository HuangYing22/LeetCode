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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        
        unordered_set<ListNode*> nodeSet;
        ListNode* node = head;
        
        while(node != NULL) {
            unordered_set<ListNode*>::const_iterator it = nodeSet.find(node);
            if(it == nodeSet.end()) {
                nodeSet.insert(node);
                node = node -> next; 
            } else
                return true;
        }
        
        return false;
    }
};
