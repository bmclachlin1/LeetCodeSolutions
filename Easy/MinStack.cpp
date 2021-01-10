class MinStack {   
    // default stack
    stack<int> actualStack;
    // stack which maintains minimum value for constant time 
    // O(1) lookup
    stack<int> minStack;
    
public:
    /** initialize your data structure here. */
    MinStack() = default;
    
    /**
     * @brief Push element x onto stack
     *
     * Push element onto actualStack
     * If minStack is empty, push onto minStack as well
     * If x is less than or equal to minStack's top element, 
     * push x onto minStack as well
     */
    void push(int x) {
        actualStack.push(x);
        
        if (minStack.empty()) {
            minStack.push(x);
        } else if (x <= minStack.top()) {
            minStack.push(x);
        }
    }

    /**
     * @brief Removes the element on top of the stack
     *
     * Remove the element from actualStack
     * if removed element is equal to minStack's top element,
     * remove minStack's top element
     */
    void pop() {
        int elemToDelete = actualStack.top();
        actualStack.pop();
        
        if (elemToDelete == minStack.top()) {
            minStack.pop();
        }
    }
    
    /**
     * @brief Get the top element
     */
    int top() {
        return actualStack.top();
    }
    
    /**
     * @brief Retrieve the minimum element in the stack
     */
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */