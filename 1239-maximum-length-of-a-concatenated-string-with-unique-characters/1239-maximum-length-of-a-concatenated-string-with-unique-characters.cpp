class Solution {
public:
    int res = INT_MIN;
    int maxLength(vector<string>& arr) 
    {
        unordered_set<char> st;
        f(arr,0,st);
        
        return res;
    }
    void f(vector<string>&arr, int index,unordered_set<char>st)
    {
        if(index>=arr.size())
        {
            res = max(res, (int)st.size());
            return;
        }
        
        unordered_set<char> temp(st);
        temp.insert(arr[index].begin(),arr[index].end());
        
        if(temp.size()==arr[index].size()+st.size())
        {
            f(arr,index+1,temp);
        }
        
        f(arr,index+1,st);
    }
};