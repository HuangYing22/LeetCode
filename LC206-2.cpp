//LC206
//最重要
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode dummyNode(0);
        dummyNode.next = head;
        
        ListNode* ptr = &dummyNode;
        ListNode* cur = ptr->next;
      
      
        while(cur->next != NULL) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ptr->next;
            ptr->next = move;
        }
        
        
        //Traverse Linklist 输出内容
        ListNode* p = dummyNode.next;
        //while(p->next != NULL) { //最后一个node的next就是NULL,最后一个node不会被cout
        while(p != NULL) {
            cout << p->val << endl;
            p = p->next;
        }
        
        return dummyNode.next;
    }
    
};
