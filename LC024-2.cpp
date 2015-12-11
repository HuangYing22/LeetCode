//LC24
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* ptr = &dummyNode;
        ListNode* cur = ptr->next;
        
        while((cur != NULL) && (cur->next != NULL)) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ptr->next;
            ptr->next = move;
            
            ptr = cur;
            cur = cur->next;
        }
        
        
        //打印Linked List
        ListNode* p = dummyNode.next;
        while(p != NULL) {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        
        return dummyNode.next;
    }
};
