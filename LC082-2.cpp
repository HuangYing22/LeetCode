class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;  
        ListNode dummy(0);  
        dummy.next = head;  
        ListNode* cur = &dummy;
        ListNode* next = head;  //改掉命名
        while(next != NULL) {
            bool isDup = false;  
            while(next->next != NULL && next->val == next->next->val) {  
                isDup = true;
                ListNode* temp = next;
                next = next->next;
                delete temp;
            }  

            if(isDup) { //删掉4 4 4 5中的最后一个4
                ListNode* temp = next;
                next = next->next;
                delete temp;
                continue;
            }  

            cur->next = next;
            cur = cur->next;
            next= next->next;
        }  
        cur->next = next;
        return dummy.next;
    }  
};
