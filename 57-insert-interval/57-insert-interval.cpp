class Solution
{
    public:
        vector<vector < int>> insert(vector<vector < int>> &arr, vector< int > &ni)
        {
            arr.push_back(ni);

            sort(arr.begin(), arr.end());
            vector<vector < int>> res;

            res.push_back(arr[0]);

            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i][0] > res.back()[1])
                {
                    res.push_back(arr[i]);
                }
                else
                {
                    res.back()[1] = max(res.back()[1], arr[i][1]);
                }
            }

            return res;
        }
};