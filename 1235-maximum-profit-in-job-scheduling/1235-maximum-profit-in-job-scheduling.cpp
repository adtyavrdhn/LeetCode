class Solution
{
    public: vector<int> dp;
    int jobScheduling(vector<int> &s, vector<int> &e, vector< int > &p)
    {
        int n = s.size();
        
        dp.resize(n,-1);

        vector<vector < int>> arr;

        for (int i = 0; i < n; i++)
        {
            arr.push_back({ s[i],
                e[i],
                p[i] });
        }

        sort(arr.begin(), arr.end());
        return f(arr, 0);
    }

    int f(vector<vector < int>> &arr, int i)
    {
        if (i >= arr.size())
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int take = 0, ntake = 0;
        ntake = f(arr, i + 1);

        int in = find(arr, arr[i][1], i);

        int res = max(ntake, arr[i][2] + f(arr, in));

        return dp[i] = res;
    }
    int find(vector<vector < int>> &arr, int end, int i)
    {
        int l = i + 1;
        int r = arr.size() - 1;

        int ind = arr.size();

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (arr[mid][0] >= end)
            {
                ind = min(ind, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ind;
    }
};