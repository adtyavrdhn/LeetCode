class Solution
{
    public:
        vector<vector < int>> res;

    vector<vector < int>> combinationSum2(vector<int> &arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> temp;

        f(arr, target, 0, temp);

        return res;
    }
    void f(vector<int> &arr, int target, int i, vector<int> &temp)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }

        for (int j = i; j < arr.size(); j++)
        {
            if (j == i || arr[j] != arr[j - 1])
            {
                if (arr[j] <= target)
                {
                    temp.push_back(arr[j]);
                    f(arr, target - arr[j], j + 1, temp);
                    temp.pop_back();
                }
            }
        }
    }
};