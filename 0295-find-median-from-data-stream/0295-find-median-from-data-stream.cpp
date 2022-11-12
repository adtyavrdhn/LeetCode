class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(small.empty() || num<small.top())
            small.push(num);
        else
            large.push(num);
        
        if(small.size() > large.size() && small.size() - large.size() > 1)
        {
            int n = small.top();
            small.pop();
            large.push(n);
        }
        
        if(large.size() > small.size() && large.size() - small.size() > 1)
        {
            int n = large.top();
            large.pop();
            small.push(n);
        }
    }
    
    double findMedian() 
    {
        double median;
        
        if(small.size() > large.size())
            median = small.top();
        
        else if(large.size() > small.size())
             median = large.top();
        
        else {
           median = (large.top() + small.top()) / 2.0;
        }
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */