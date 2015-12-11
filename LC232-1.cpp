//LC232
//O(n)
class Queue {
private:
    stack<int> st1;
    stack<int> st2;
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        st1.push(x);
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        
        st2.push(x);
        while(st1.top() != x) {
            st2.push(st1.top());
            st1.pop();
        }
        
        return;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st2.pop();
        int nhead;
        
        if(! st2.empty()) {
            nhead = st2.top();
        } else {
            st1.pop();
            return;
        }
        
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        st2.pop();
        
        st1.push(st2.top());
        st2.pop();
        
        while(st2.top() != nhead) {
            st1.push(st2.top());
            st2.pop();
        }
        
        return;
    }

    // Get the front element.
    int peek(void) {
        return st2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st1.empty();
    }
};

//Haochen Liu's正解:
//对每个元素来看,经历的时间是const
