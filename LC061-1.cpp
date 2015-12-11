//LC61
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if((head == NULL) || (head->next == NULL) ||(k == 0)) return head;
        
        ListNode dummyNode(0);
        
        ListNode* ptr = head;
        int n = 1;
        while(ptr->next != NULL) {
            n++;
            ptr = ptr->next;
        }
        
        //Note: k might >= n;
        int m;
        if(k%n == 0) return head;
        if(n < k) {
            m = n-k%n;
        } else {
            m = n-k;
        }
        
        ptr = head;
        for(int i=0; i<m-1; i++) {
            ptr = ptr->next;
        }
        
        dummyNode.next = ptr->next;
        ptr->next = NULL;
        
        ptr = dummyNode.next;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        
        ptr->next = head;
        return dummyNode.next;
    }
};
