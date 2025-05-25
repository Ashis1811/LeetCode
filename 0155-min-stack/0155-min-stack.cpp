class MinStack {
public:
    stack<int> st;
    stack<int> minst; //Auxilliary stack to track minimum
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || val <= minst.top())
        {
            minst.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minst.top())
        {
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        int data = st.top();
        return data;
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */