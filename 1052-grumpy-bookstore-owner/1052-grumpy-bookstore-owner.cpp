class Solution
{
    public:
        int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
        {
            int n = grumpy.size();
            
            int sum = 0;
            
            for (int i = 0; i < n; i++)
                if (grumpy[i] == 0)
                    sum += customers[i];

            int i = 0,j = 0;
            
            int res = 0;
            
            while (j < n)
            {
                if (grumpy[j] == 1)
                    sum += customers[j];
                
                if (j - i + 1 < minutes)
                    j++;
                
                else if (j - i + 1 == minutes)
                {
                    res = max(res, sum);
                    
                    if (grumpy[i] == 1)
                        sum -= customers[i];
                    
                    i++;
                    j++;
                }
            }
            
            return res;
        }
};