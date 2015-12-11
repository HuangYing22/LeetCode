//LC234
//Time Limit Exceeded
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return true;
        int num = 1;
        ListNode* ptr = head;
        while(ptr->next != NULL) {
            num ++;
            ptr = ptr->next;
        }
        return isPalindrome(head, num);
    }
    
    bool isPalindrome(ListNode* head, int n) {
        if((head == NULL) || (head->next == NULL)) return true;

        ListNode* ptr = head;
        for(int i=0; i<n-1; i++) {
            if(ptr->next == NULL) {
                break;
                return false;
            }
            ptr = ptr->next;
        }
        if(head->val != ptr->val) return false;
        return isPalindrome(head->next, n-2);
    }
};
*/

//Wrong Answer
//Reverse Function改变了head这一串Link List的mapping!!! 相当于原来以head为头的Link List不存在了
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return true;
        
        ListNode* rev = reverseLinkList(head);
        
        cout<<"Main Original:"<<endl;
        ListNode* p = head;
        while(p!=NULL) {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        
        
        cout<<"Main Reversed:"<<endl;
        p = rev;
        while(p!=NULL) {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        
        ListNode* pt1 = head;
        ListNode* pt2 = rev;
        
        while((pt1->next != NULL) && (pt2->next != NULL)) {
            cout<<"!!!"<<endl;
            cout<<pt1->val<<" "<<pt2->val<<endl;
            if(pt1->val != pt2->val) return false;
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
        return true;
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
        
        cout<<"In reverse function:"<<endl;
        
        ListNode* p = dummyNode.next;
        while(p!=NULL) {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        
        return dummyNode.next;
    }
};
*/

/*
In reverse function:
3 2 1
Main Original:
1
Main Reversed:
3 2 1
*/

//Reverse一半即可
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return true;
        
        //Find tot num of elements in the LinkList
        int num = 1;
        ListNode* ptr = head;
        while(ptr->next != NULL) {
            num ++;
            ptr = ptr->next;
        }
        
        ptr = head;
        int mid = (num%2 == 0)? num/2 : (num/2+1);
        
        for(int i=1; i<mid; i++) {
           ptr = ptr->next; 
        }
        //ptr此时是前一半的最后一个(偶), 或者中点(奇)
        ptr->next = reverseLinkList(ptr->next);
        ptr = ptr->next;

        ListNode* fro = head;
        while(ptr != NULL) {
            if(fro->val != ptr->val) return false;
            fro = fro->next;
            ptr = ptr->next;
        }
        return true;
    }
    
    //After calling this reverseLinkList function, head pointer no longer maintains the original Linklist.
    //这一片内存里的指向关系已经变了, 原来的Linklist没有了
    //新的Linklist以dummyNode.next为头
    //head还是指向原来的头元素,但是它现在在最后一个,head->next == NULL!!!
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
};
