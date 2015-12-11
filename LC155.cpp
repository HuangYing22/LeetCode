//LC155
//Special Requirement Data Structure
//push新元素进来的时候,如果它比当前的Min更小或相等,就放进minE里,成为新的Min
//minE的top保证一定是当前stack的元素中最小的

//pop出去的时候,如果元素大于Min, minE不受影响
//如果就是Min, 把Min也从minE里pop出去
//不可能比Min更小,否则它也已经在minE里了

//假设有一个次小的Min,如果它比真正的Min来得早, 它会在minE里也压在Min底下, 轮到它pop的时候才会pop出去minE; 如果它比真正的Min来得晚, 它不会出现在minE里面

//当最后一个Min从minE里pop出去的时候, 它一定是当前stack里最小的, stack里在它底下的都比它大,但是这样的话比它大的元素一定会在minE里它的底下, 所以不可能minE空了的时候stack里还有东西; stack里在它底下的不可能比它小,否则它不会进入minE

//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.

class MinStack {
private:
    stack<int> minE;
    stack<int> st;
public:
    void push(int x) {
        st.push(x);
        if(minE.empty() || (x <= minE.top())) minE.push(x);
        return;
    }

    void pop() {
        if(st.top() == minE.top()) minE.pop();
        st.pop();
        return;
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minE.top();
    }
};
