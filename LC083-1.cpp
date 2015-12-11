//LC83
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode* cur = head;
        ListNode* aft;
        
        while((cur != NULL) && (cur->next != NULL)) {
            //这一层动了cur,没有动aft,所以只check cur,不用check aft
            aft = cur->next;
            while((aft != NULL) && (cur->val == aft->val)) { 
                //每一层while loop看cur,aft的val之前 都要看看是不是NULL;每一层cur,aft动了之后都要check
                //这一层动了aft,没有动cur,所以只check aft,不用check cur
                aft = aft->next;
                cur->next = aft;
            }
            cur = aft;
        }
        
        //Traverse Linklist 输出内容
        ListNode* ptr = head;
        //while(ptr->next != NULL) { //最后一个node的next就是NULL,最后一个node不会被cout
        cout<<"Printing Linklist:"<<endl;
        while(ptr != NULL) {
            cout << ptr->val << endl;
            ptr = ptr->next;
        }
        
        return head;
    }

};
