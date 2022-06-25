class Solution
{
    public:
        vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        return parent[x] == x ? x : find(parent[x]);
    }
    void union_p(int i, int j)
    {
        int x = find(i);
        int y = find(j);

        if (x != y)
        {
            if (rank[x] > rank[y])
            {
                parent[y] = x;
                rank[x]++;
            }
            else
            {
                parent[x] = y;
                rank[y]++;
            }
        }
    }
    long long countPairs(int n, vector<vector < int>> &arr)
    {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            int a = arr[i][0];
            int b = arr[i][1];

            int x = find(a);
            int y = find(b);

            if (x != y)
            {
                union_p(a, b);
            }
        }

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[find(i)]++;
        }

        long long ans = 0;
        
        vector<int> nums;
        
        for (auto i: mpp)
        {
              nums.push_back(i.second);
        }
          
        long long sum = nums.back();
        
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            ans += sum *nums[i];
            sum += nums[i];
        }
        
        return ans;
    }
};