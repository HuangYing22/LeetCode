//LC82
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* cur = &dummyNode;
        ListNode* ptr = cur->next;
        int ptr_v;
        while(ptr->next != NULL){
            ptr = cur->next;
            ptr_v = ptr->val;
            if((ptr==NULL) || (ptr->next == NULL)) break;
            if(ptr->next->val != ptr_v) {
                cur = cur->next;
            } else {
                while((ptr->next!=NULL) && (ptr->next->val == ptr_v)) {
                    ListNode* tmp = ptr;
                    ptr = ptr->next;
                    delete tmp;
                }
                cur->next = ptr->next;
                delete ptr;
            }
        }
        
        return dummyNode.next;
        
    }
};
