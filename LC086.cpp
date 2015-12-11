//LC86
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if((head == NULL) || (head->next == NULL)) return head;
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* ptr = &dummyNode;
        ListNode* pre = &dummyNode;
        ListNode* cur = head;
        
        bool foundCur = false; //TODO : 没有必要
        
        while(ptr->next != NULL) {
            if(!foundCur) {
                if(ptr->next->val >= x) {
                pre = ptr;
                cur = ptr->next;
                foundCur = true;
                } 
            } else {
                if(ptr->next->val <x) {
                    ListNode* move = ptr->next;
                    ptr->next = move->next;
                    pre->next = move;
                    move->next = cur;
                    pre = pre->next;
                    continue;
                }
            }
            ptr = ptr->next;
        }
        return dummyNode.next;
    }
};
