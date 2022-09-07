class MinStack {
public:
    
    vector<int> arr;
    vector<int> min;
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        arr.push_back(val);
        if(min.empty() || val<min.back()) 
            min.push_back(val);
        else min.push_back(min.back());
    }
    
    void pop() 
    {
        arr.pop_back();
        min.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return min.back();
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