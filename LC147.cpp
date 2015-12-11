//LC147
// Sort a linked list using insertion sort.
// Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. 
// Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
// It repeats until no input elements remain.
// Sorting is typically done in-place, by iterating up the array, growing the sorted list behind it. 
// At each array-position, it checks the value there against the largest value in the sorted list (which happens to be next to it, in the previous array-position checked). 
// If larger, it leaves the element in place and moves to the next. 
// If smaller, it finds the correct position within the sorted list, shifts all the larger values up to make a space, and inserts into that correct position.
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        ListNode dummyNode(INT_MIN);
        dummyNode.next = head;
        ListNode* tail = head; //当前已经排好序部分的最后一个
        ListNode* cur = tail->next;
        
        while(tail->next != NULL) {
            cur = tail->next; //未排序部分的第一个
            ListNode* ptr = &dummyNode;
            while(ptr != tail) {
                if((ptr->val <= cur->val) && (ptr->next->val > cur->val)) {
                    tail->next = cur->next;
                    cur->next = ptr->next;
                    ptr->next = cur;
                    break;
                }
                ptr = ptr->next;
            }
            //表示cur比tail大,tail后移一个
            if(ptr == tail) tail = tail->next;
        }
        
        return dummyNode.next;
    }
};
