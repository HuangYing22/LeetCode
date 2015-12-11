//LC203
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        if((head->next == NULL) && (head->val != val)) return head;
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* pre = &dummyNode;
        ListNode* ptr = pre->next;
        
        while(pre->next != NULL) {
            if(ptr->val == val) {
                pre->next = ptr->next; //先用后删,或者用temp指代一下,否则risky
//delete之后,如果别人没有改动它,可能还可以看, 但是万一别的地方改了它,就错了
//这块内存是free了, 别人可以用了,不一定改了
//万一别人改了它,再去看它就错了
                delete(ptr);
            } else {
                pre = pre->next;
            }
            ptr = pre->next;
        }
        return dummyNode.next;
        
    }
};
