class Solution
{
    public:
        bool static comp(vector < int>
            const &a, vector < int>
            const &b)
        {
            return (a[1] > b[1]);
        }

    int maximumUnits(vector<vector < int>> &boxes, int truckSize)
    {
        int n = boxes.size();

        sort(boxes.begin(), boxes.end(), comp);

       	// for (auto i: boxes) 
       	// {
       	//     for (auto j: i)
       	//     {
       	//         cout<<j<<" ";
       	//     }
       	//     cout<<endl;
       	// }
        int sum =0;
        for (int i = 0; i < n; i++) 
        {
            int count = boxes[i][0];
            while(truckSize > 0 && count > 0)
            {
                sum+= boxes[i][1];
                count--;
                truckSize--;
            }
        }
        
        return sum;
    }
};