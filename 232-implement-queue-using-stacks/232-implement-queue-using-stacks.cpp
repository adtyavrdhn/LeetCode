class MyQueue {
public:
    stack<int> s1,s2;
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        // copy to s2
        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        // copy to s2
        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() and s2.empty();
    }
};
