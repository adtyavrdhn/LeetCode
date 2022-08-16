class Solution
{
    public:
    
    unordered_map<string, bool> mpp;
    vector<bool> dp;
    
    bool wordBreak(string s, vector<string> &dict)
    {
        int n = s.size();
        dp.resize(n + 1, false);

        for (auto i: dict)
        {
            mpp[i] = true;
        }

        dp[n] = true;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (mpp[s.substr(i, j - i + 1)] && dp[j + 1])
                {
                    dp[i] = true;
                }
            }
        }

       return dp[0];
    }
   	//     bool f(string s, int index)
   	//     {
   	//         if(index==s.size())
   	//         {
   	//             return true;
   	//         }

   	//         if(dp[index]!=-1)
   	//         {
   	//             return dp[index];
   	//         }

   	//         for(int i=index;i < s.size();i++)
   	//         {
   	//             if(mpp[s.substr(index,i-index+1)] && f(s,i+1))
   	//             {
   	//                 return dp[index] = true;
   	//             }
   	//         }

   	//         return dp[index] = false;
   	//     }
};