class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) 
    {
        int n = pos.size();
        vector<vector<int>> arr;
        
        for(int i=0;i<n;i++)
        {
            arr.push_back({pos[i],speed[i]});
        }
        
        sort(arr.begin(),arr.end());
        
        stack<double> st;
        
        st.push((double)(target -arr[n-1][0])/(double) arr[n-1][1]);
        
        for(int i=n-2;i>=0;i--)
        {
            double t = (double)(target-arr[i][0])/(arr[i][1]*1.0);
            
            auto tst = st.top();
            
            if(tst<t)
            {
                st.push(t);
            }
        }
        
        return st.size();
    }
};