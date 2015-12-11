//**LC23
//正解1
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
// A priority queue is an abstract data type which is like a regular queue or stack data structure, but where additionally each element has a "priority" associated with it. In a priority queue, an element with high priority is served before an element with low priority.
class MyCompare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; //大于！
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, MyCompare> q;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != NULL) {
                q.push(lists[i]);
            }
        }
        
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(!q.empty()) {
            ListNode* node = q.top(); //最小还是最大?
            q.pop();
            cur->next = node;
            cur = cur->next;
            if(node->next != NULL) {
                q.push(node->next);
            }
        }
        return dummy.next;
    }
    
};
