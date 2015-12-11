//Better正解
//这样不算改了原来的LinkList!
//只要指向关系没有改就ok
//headA headB不需要还是指向头元素
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = getCnt(headA);
        int cntB = getCnt(headB);
        
        if(cntA > cntB) {
            for(int i=0; i<(cntA-cntB); i++) {
                headA = headA->next;
            }
        }
        if(cntB > cntA) {
            for(int i=0; i<(cntB-cntA); i++) {
                headB = headB->next;
            }
        }
        
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }

private:
    int getCnt(ListNode* head) {
        int res = 0;
        ListNode* ptr = head;
        while(ptr != NULL) {
            ptr = ptr->next;
            res ++;
        }
        return res;
    }
};
