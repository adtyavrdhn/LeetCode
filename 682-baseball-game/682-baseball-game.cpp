class Solution {
public:
    int calPoints(vector<string>& s) 
    {
        int n = s.size();
        vector<int> arr;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=="+")
            {
                int k = arr.size()-1;
                int t = arr[k]+arr[k-1];
                res+=t;
                arr.push_back(t);
            }
            else if(s[i]=="D")
            {
                int k = arr.size()-1;
                int t = 2*arr[k];
                arr.push_back(t);
                res+=t;
            }
            else if(s[i]=="C")
            {
                int k = arr.size()-1;
                res-=arr[k];
                arr.pop_back();
            }
            else
            {
                int t = stoi(s[i]);
                arr.push_back(t);
                res+=t;
            }
            
        }
        return res;
    }
};