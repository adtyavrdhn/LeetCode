class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) 
    {
        int left  = 1;
        int right = (int)1e6;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            int sum = 0;
            for(int i=0;i<q.size();i++)
            {
                sum+=((q[i]+mid-1)/mid);
                    // +mid -1 is the same as ceil() fncn
            }
            
            if(sum>n)
                left = mid + 1;
            else
                right = mid-1;
        }
        
        return left;
    }
};