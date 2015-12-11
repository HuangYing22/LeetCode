//LC206
//最重要
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next; //ListNode* next; ListNode*表示next这个object的地址 ListNode next表示next这个object
 *     ListNode(int x) : val(x), next(NULL) {} //constructor初始化的函数
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode* cur = head;
        ListNode* bef = NULL;
        ListNode* aft;
        
        while(cur->next != NULL) {
            aft = cur->next;
            cur->next = bef;
            bef = cur;
            cur = aft;
        }
        
        cur->next = bef;
        head = cur;
        
        
        //Traverse Linklist 输出内容
        ListNode* ptr = head;
        //while(ptr->next != NULL) { //最后一个node的next就是NULL,最后一个node不会被cout
        while(ptr != NULL) {
            cout << ptr->val << endl;
            ptr = ptr->next;
        }
        
        return head;
    }
    
};
