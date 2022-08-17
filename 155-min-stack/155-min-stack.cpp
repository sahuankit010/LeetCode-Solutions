class MinStack {
public:
    
    stack<int>st;
    stack<int>aux;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            aux.push(val);
            return;
        }
        st.push(val);
        if(st.top()<=aux.top())
            aux.push(val);
    }
    
    void pop() {
        if(aux.top()==st.top()) aux.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return aux.top();
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