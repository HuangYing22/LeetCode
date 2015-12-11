//Better正解
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while((fast->next != NULL) && (fast->next->next != NULL)) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* pmid = slow->next;
        slow->next = NULL;
        
        head = sortList(head);
        pmid = sortList(pmid);
        
        ListNode dummyNode(0);
        ListNode*ptr = &dummyNode;
        ListNode* p1 = head;
        ListNode* p2 = pmid;
        
        while((p1 != NULL) && (p2 != NULL)) {
            if(p1->val < p2->val) {
                ptr->next = p1;
                p1 = p1->next;
                ptr = ptr->next;
            } else {
                ptr->next = p2;
                p2 = p2->next;
                ptr = ptr->next;
            }
        }
        
        if(p1 != NULL) {
            ptr->next = p1;
            return dummyNode.next;
        }
        
        ptr->next = p2;
        return dummyNode.next;
    }
};
