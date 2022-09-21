class MedianFinder {
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(small.empty() || num<small.top()) small.push(num);
        else large.push(num);
        
        if(small.size()>large.size() && small.size()-large.size()>1){
            int top = small.top();
            small.pop();
            large.push(top);
        }
        
        if(large.size()>small.size() && large.size()-small.size()>1){
            int top = large.top();
            large.pop();
            small.push(top);
        }
    }
    
    double findMedian() 
    {
        double median;
        if(small.size()==large.size()){
            median = ((double)small.top()+(double)large.top())/2;
        }else{
            median = small.size()>large.size() ? small.top() : large.top();
        }
        return median;
    }
};
