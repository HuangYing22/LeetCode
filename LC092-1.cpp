class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        if(head->next == NULL) return head;
        
        int counter = 1;
        ListNode* ptr = head;
        ListNode* tail_1 = head;
        
        while(counter < m) {
            tail_1 = ptr;
            ptr = ptr->next;
            counter ++;
        }
        //出while loop的时候tail_1是第m-1个, ptr是第m个
        //tail_1是不用排序的部分的尾巴
        
        ListNode* tail = ptr;
        ListNode* aft = ptr->next;
        
        while(counter < n) {
            aft = tail->next; //tail是要排序的部分的尾巴
            tail->next = aft->next;
            aft->next = ptr;
            
            if(m != 1) tail_1->next = aft; //把不用排序部分的尾巴指向当前排好序部分的开头
            
            ptr = aft; //ptr后移1个,即当前排好序部分的开头
            counter ++;        
        }
        
        if(m == 1) head = ptr;
        
        //打印Linked List
        ListNode* p = head;
        while(p != NULL) {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        
        return head;
    }
};
