class MyCalendarThree {
public:
    map<int,int> mpp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) 
    {
        mpp[start]++,mpp[end]--;
        
        int res = 1,sum=0;
        for(auto i : mpp)
        {
            sum+= i.second;
            res = max(res,sum);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */