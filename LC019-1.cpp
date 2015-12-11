//LC19
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if((head == NULL) || (n == 0)) return head;
        
        int num = 1;
        ListNode* ptr = head;
        while(ptr->next != NULL) {
            num ++;
            ptr = ptr->next;
        }
        
        if(n > num) return head;
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        
        int m = num - n;
        ptr = &dummyNode;
        for(int i=0; i<m; i++) {
            ptr = ptr->next;
        }
        
        ptr->next = ptr->next->next;
        return dummyNode.next;
        
    }
};
