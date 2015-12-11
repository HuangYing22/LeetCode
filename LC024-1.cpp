//LC24
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode* ptr = head;
        ListNode* aft = head->next;
        head = head->next;
        
        while((ptr != NULL) && (ptr->next != NULL)) {
            
            aft = ptr->next;
            ptr->next = aft->next;
            aft->next = ptr;
            
            ptr = ptr->next;
            
            if((ptr != NULL) && (ptr->next != NULL)) {
                aft->next->next = ptr->next;
            }
        }
        
        
        //打印Linked List
        ListNode* p = head;
        while(p != NULL) {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        
        return head;
    }
};
