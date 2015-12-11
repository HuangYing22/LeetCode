//LC25
//Time O(n^2)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if((head == NULL) || (k == 1)) return head;
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* ptr = &dummyNode;
        ListNode* cur = ptr->next;
        
        int i = 1;
        int counter = 1;
        while((cur != NULL) && (cur->next != NULL)) {
            
            ListNode* p1 = cur;
            while(p1->next != NULL) {
                p1 = p1->next;
                counter++;
            }
            
            if(counter < k) break;
            
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ptr->next;
            ptr->next = move;
            
            i++;
            
            if(i > k-1) {
                ptr = cur;
                cur = cur->next;
                i = 1;
                counter = 1;
            }
        } 
        
        ListNode* p = dummyNode.next;
        while(p != NULL) {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        
        return dummyNode.next;    
            
    }
};
