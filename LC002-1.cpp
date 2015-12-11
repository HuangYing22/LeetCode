//LC2
//You are given two linked lists representing two non-negative numbers. 
//The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* pre = l1;
        ListNode* pt1 = l1;
        ListNode* pt2 = l2;
        int c = 0;
        
        while((pt1 != NULL) && (pt2 != NULL)) {
            pt1->val += pt2->val + c;
            if(pt1->val >=10 ) {
                pt1->val -= 10;
                c = 1;
            } else {
                c = 0;
            }
            pre = pt1;
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
        
        if((pt1 != NULL) && (pt2 == NULL)) {
            if(c == 0) return l1;
            while(pt1 != NULL) {
                pt1->val += c;
                if(pt1->val < 10) break;
                pt1->val -=10;
                c = 1;
                pre = pt1;
                pt1 = pt1->next;
            }
        }
        
        if((pt1 == NULL) && (pt2 != NULL)) {
            pre->next = pt2;
            if (c == 0) return l1;
            while(pt2 != NULL) {
                pt2->val += c;
                if(pt2->val < 10) break;
                pt2->val -= 10;
                c = 1;
                pre = pt2;
                pt2 = pt2->next;
            }
        }

        if((pt1 == NULL) && (pt2 == NULL)) {
            if(c == 0) return l1;
            ListNode* carry = new ListNode(1);
            pre->next = carry;
        }
        return l1;
    }

};

//注意:如果写为静态声明,会在test case ex.[5] [5]出现run time error!!! 静态声明出了{}就没了
/*
         if((pt1 == NULL) && (pt2 == NULL)) {
            if(c == 0) return l1;
            ListNode dummyNode(1);
            pre->next = &dummyNode;
            return l1;
        }
*/
