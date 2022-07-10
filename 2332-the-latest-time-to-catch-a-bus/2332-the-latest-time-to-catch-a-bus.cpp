class Solution
{
    public:
        int latestTimeCatchTheBus(vector<int> &buses, vector<int> &pass, int cap)
        {

            sort(buses.begin(),buses.end());
            sort(pass.begin(),pass.end());
            
            queue<int> q;
            set<int> st;
            
            for(auto p : pass)
            {
                q.push(p);
                st.insert(p);
            }
            
            int res = 0;
            
            for(int i=0;i<buses.size();i++)
            {
                int depart = buses[i];
                
                int count = 0;
                
                int p =0;
                
                
                while(!q.empty() && count < cap && q.front()<=depart)
                {
                    p = q.front();
                    q.pop();
                    
                    if(st.find(p-1)==st.end())
                    {
                        res = p - 1;
                    }
                    count++;
                }
                
                if(count < cap)
                {
                    while(st.find(depart)!=st.end())
                        depart--;
                    
                    res = max(res,depart);
                }
            }
            
            return res;
        }

   	// https://leetcode.com/problems/the-latest-time-to-catch-a-bus/discuss/2259176/Easy-C%2B%2B-Solution-Using-Queue-And-Set-or-optimised-without-queue
};