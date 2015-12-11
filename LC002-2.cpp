//Better正解
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode dummyNode(0);
        ListNode* cur = &dummyNode;
        int carry = 0;
        
        while((l1 != NULL) || (l2 != NULL) || (carry != 0)) {
            if(l1 != NULL) {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                carry += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(carry%10); //如果carry > 10,取个位
            carry /= 10; //如果carry > 10, carry = 1
            cur = cur->next;
        }
        return dummyNode.next;
    }

};
