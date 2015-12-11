class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        
        int curSize = lists.size();

        while (curSize > 1) {
            int halfSize = (curSize + 1)/2;
            for(int i=0; (i<halfSize) && (i+halfSize < curSize); i++) {
                ListNode* l1 = lists[i];
                ListNode* l2 = lists[i+halfSize];
                ListNode* l = merge2Lists(l1, l2);
                lists[i] = l;
            }
            curSize = halfSize;
        }
        return lists[0];
    }
};
