//Better正解
//Try to do this in one pass.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if((head == NULL) || (n == 0)) return head;
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* ptr = &dummyNode;
        ListNode* del = ptr;
        for(int i=0; i<n; i++) {
            del = del->next;
        }
        
//这样算是one pass
//但是操作数目和我的解法扫一边半是一样的
//one pass一个loop里做的事情越多越好
        while(del->next != NULL) {
            ptr = ptr->next;
            del = del->next;
        }
        
        del = ptr->next;
        ptr->next = ptr->next->next;
        delete(del); //很重要,否则memory leak,永远占着它

        return dummyNode.next;
        
    }
};
