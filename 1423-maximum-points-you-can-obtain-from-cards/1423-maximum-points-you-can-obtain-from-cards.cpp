class Solution
{
    public:
        int maxScore(vector<int> &cards, int k)
        {
            int n = cards.size();
            
            int sum = 0, res = INT_MIN;
            for(int i=0;i<k;i++)
            {
                sum+= cards[i];
            }
            res = sum;
            for(int i=0;i<k;i++)
            {
                sum-= cards[k-i-1];
                sum+= cards[n-i-1];
                res = max(sum,res);
            }
            
            return res;
        }
};