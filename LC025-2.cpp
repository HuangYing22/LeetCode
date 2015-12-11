//Time O(n)
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
    	if((head == NULL) || (k == 1)) return head;
   	 
    	ListNode dummyNode(0);
    	dummyNode.next = head;
    	ListNode* ptr = &dummyNode;
    	ListNode* cur = ptr->next;
   	 
    	int i = 1;
    	bool flag = true;
   	 
    	while((cur != NULL) && (cur->next != NULL)) {
       	 
        	ListNode* p1 = ptr->next;
        	for(int j=1; j<k; j++){
            	p1 = p1->next;
            	if(p1 == NULL) {
                	flag = false;
                	break;
            	}
        	}
       	 
        	if(!flag) break;
       	 
        	ListNode* move = cur->next;
        	cur->next = move->next;
        	move->next = ptr->next;
        	ptr->next = move;
       	 
        	i++;
       	 
        	if(i > k-1) {
            	ptr = cur;
            	cur = cur->next;
            	i = 1;
        	}
    	}
   	 
    	return dummyNode.next;
	}
};
