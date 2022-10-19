class Solution
{
    public:
        class Compare
        {
            public:
                bool operator()(pair<int, string>&a, pair<int, string>&b)
                {
                    if(a.first>b.first)
                        return false;
                    
                    if(a.first==b.first)
                    {
                        return b<a;
                    }
                    
                    return true;
                }
        };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> mpp;
        for (auto i: words)
        {
            mpp[i]++;
        }

        priority_queue<pair<int, string>,vector<pair<int,string>>,Compare> pq;
        for (auto i: mpp)
        {
            pq.push({ i.second,i.first});
        }

        vector<string> res;
        while (!pq.empty() && k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};