class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if((head == NULL) || (head->next == NULL) || (m == n)) return head;
        
        //函数外面不再引用dummyNode,所以不用动态声明
        //好处:不用动态声明,不用额外手工释放内存
        ListNode dummyNode(0);
        ListNode* ptr = &dummyNode;
        ptr->next = head;
        
        for(int i=0; i<m-1; i++) {
            ptr = ptr->next;
        }
        
        ListNode* cur = ptr->next;
        
        //好处:每次loop完成是一个完整的链,不是断开的
        for(int i=0; i<n-m; i++) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ptr->next;
            ptr->next = move;
        }
        
        //打印Linked List
        ListNode* p = head;
        while(p != NULL) {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        
        return dummyNode.next;
    }
};
