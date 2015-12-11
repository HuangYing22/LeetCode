//**LC21 看答案
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode dummyNode(0);
        ListNode* cur = &dummyNode;
        
        while((l1 != NULL) || (l2 != NULL)) {
            if(l1 == NULL) {
                cur->next = l2;
                break;
            }
            
            if(l2 == NULL) {
                cur->next = l1;
                break;
            }
            
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        
        return dummyNode.next;
    }
};

/*
错误解答
......
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } 
            
            if(l1->val >= l2->val) { 
//此时会出现run time error,因为l1已经移过了,很可能l1已经是NULL了,不能再次访问 l1->val
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
......
*/
