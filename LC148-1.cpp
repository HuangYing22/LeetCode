//LC148
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode dummyNode(0);
        ListNode* ptr = head;
        
        int n = 1;
        while(ptr->next != NULL) {
            n++;
            ptr = ptr->next;
        }
        
        ptr = head;
        int mid = n/2;
        for(int i=0; i<mid-1; i++) {
            ptr = ptr->next;
        }
        
        ListNode* pmid = ptr->next;
        ptr->next = NULL;
        
        head = sortList(head);
        pmid = sortList(pmid);
        
        ptr = &dummyNode;
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
        
        while(p1 != NULL) {
            ptr->next = p1;
            p1 = p1->next;
            ptr = ptr->next;
        }
        
        while(p2 != NULL) {
            ptr->next = p2;
            p2 = p2->next;
            ptr = ptr->next;
        }
        
        return dummyNode.next;
    }
};
