class MinStack {
public:
    multiset<int> st;
    stack<int> arr;
    MinStack() {
        
    }
    
    void push(int val) 
    {
        arr.push(val);
        st.insert(val);
        
    }
    
    void pop() 
    {
        st.erase(st.find(arr.top()));
        arr.pop();
    }
    
    int top() 
    {
        return arr.top();
    }
    
    int getMin() 
    {
        return *st.begin();
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