//Better正解
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if((head == NULL) || (head->next == NULL) ||(k == 0)) return head;
        
        ListNode dummyNode(0);
        
        ListNode* tail = head;
        int n = 1;
        while(tail->next != NULL) {
            n++;
            tail = tail->next;
        }
        
        //Note: k might >= n;
        k %= n;
        if (k == 0) return head;
        int m = n-k;
        
        ListNode* ptr = head;
        for(int i=0; i<m-1; i++) {
            ptr = ptr->next;
        }
        
        dummyNode.next = ptr->next;
        ptr->next = NULL;
        
        tail->next = head;
        return dummyNode.next;
    }
};
