class Solution {
public:
	void reorderList(ListNode* head) {
    	if((head == NULL) || (head->next == NULL) || (head->next->next == NULL)) return;

    	ListNode dummyNode(0);
    	dummyNode.next = head;
    	ListNode* cur = head;
   	 
    	//count the number of nodes
    	int size = 0;
    	int mid;
   	 
    	while (cur != NULL) {
        	size ++;
        	cur = cur->next;
    	}
   	 
    	if (size%2 == 0) mid = size/2;
    	else mid = (size+1)/2;
   	 
    	//Reverse up to mid point
    	ListNode* ptr = &dummyNode;
    	cur = ptr->next;
   	 
    	for(int i=1; i<mid; i++) {
        	ListNode* move = cur->next;
        	cur->next = move->next;
        	move->next = ptr->next;
        	ptr->next = move;
    	}
   	 
    	//Bring forward the second half
    	if(size%2 != 0) ptr = ptr->next;
   	 
    	for(int i=0; i<(size/2); i++) {
        	cur = ptr->next;
       	 
        	ListNode* move = head->next;
        	head->next = move ->next;
        	move->next = ptr->next;
        	ptr->next = move;
       	 
        	ptr = cur;
    	}
   	 
    	//Reverse Entire List
    	ptr = &dummyNode;
    	cur = ptr->next;
    	while(cur->next != NULL) {
        	ListNode* move = cur->next;
        	cur->next = move->next;
        	move->next = ptr->next;
        	ptr->next = move;
    	}

    	return;
	}
};
