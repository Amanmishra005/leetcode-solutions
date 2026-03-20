class MinStack {
public:
    long min;
    stack<long> st;
    MinStack() { }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min = val;
        }else{
            st.push(val - min);
                if(val < min) min = val;            
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long  pop = st.top();
        st.pop();
        if(pop < 0) min = min  - pop;
    }
    
    int top() {
        long top = st.top();
        return (top >= 0 )? (top + min) : (int)min;
    }
    
    int getMin() {
        return min;
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