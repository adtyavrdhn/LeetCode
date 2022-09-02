class Solution
{
    public:
        int eraseOverlapIntervals(vector<vector < int>> &arr)
        {
            int n = arr.size();

           sort(arr.begin(),arr.end(),[](vector<int>& b,vector<int>& c){
			return b[1]<c[1];
		});

            int count = 0;
            int end = arr[0][1];
            for (int i = 1; i < n; i++)
            {
                if (arr[i][0] < end) count++;
                else end = arr[i][1];
            }
            return count;
        }
};