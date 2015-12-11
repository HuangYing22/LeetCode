//LC160
// Write a program to find the node at which the intersection of two singly linked lists begins.
// If the two linked lists have no intersection at all, return NULL.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if((headA == NULL) || (headB == NULL)) return NULL;
        
        //see if headB is a node in headA LinkList or vise versa
        ListNode* ptr = headA;
        while(ptr->next != NULL) {
            if(ptr == headB) return ptr;
            ptr = ptr->next;
        }
        ptr = headB;
        while(ptr->next != NULL) {
            if(ptr == headA) return ptr;
            ptr = ptr->next;
        }
        
        int a = getCnt(headA);
        int b = getCnt(headB);
        
        ListNode* r1 = reverseLinkList(headA);
        ListNode* r2 = reverseLinkList(headB);
        
        //In this case headA and headB has no intersection
        if(r2 != headA) {
            headA = reverseLinkList(r1);
            headB = reverseLinkList(r2);
            return NULL;
        }
        
        int c = getCnt(r2);
        int inter = (a-b+c+1)/2;
        
        //restore original structure
        headB = reverseLinkList(r1);
        
        ptr = headA;
        for(int i=1; i<inter; i++) {
            ptr = ptr->next;
        }
        
        return ptr;
    }
    
    ListNode* reverseLinkList(ListNode* head) {
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
        return dummyNode.next;
    }
    
    int getCnt(ListNode* head) {
        if(head == NULL) return 0;
        int res = 1;
        ListNode* ptr = head;
        while(ptr->next != NULL) {
            res ++;
            ptr = ptr->next;
        }
        return res;
    }
    
    void printLinkList(ListNode* head) {
        if(head == NULL) return;
        ListNode* ptr = head;
        while(ptr != NULL) {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};
