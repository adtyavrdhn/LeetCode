class Solution
{
    public:
        bool makesquare(vector<int> &match)
        {
            int n = match.size();

            int sum = accumulate(match.begin(), match.end(), 0);

            int k = sum / 4;

            vector<int> sq(4, k);

            sort(match.rbegin(), match.rend());

            return f(match, 0, sq, n);
        }
    bool f(vector<int> &match, int index, vector<int> &sq, int n)
    {
        if (index == n)
        {
            for(int i=0;i<4;i++)
            {
                if(sq[i]!=0)
                {
                    return false;
                }
            }
            return true;
        }

        bool k = false;

        for (int i = 0; i < 4; i++)
        {
            if (sq[i] >= match[index])
            {

                sq[i] -= match[index];

                k = f(match, index + 1, sq, n);
                if (k)
                {
                    return true;
                }

                sq[i] += match[index];
            }
        }

        return false;
    }
};