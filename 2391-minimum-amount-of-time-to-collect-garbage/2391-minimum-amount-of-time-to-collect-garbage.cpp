class Solution
{
    public:
        int garbageCollection(vector<string> &garb, vector<int> &travel)
        {
            int lastp = -1, lastm = -1, lastg = -1;

            int n = garb.size();

            int res = 0;

            for (int i = 0; i < n; i++)
            {
                int p = 0, g = 0, m = 0;

                for (auto c: garb[i])
                {
                    if (c == 'G')
                    {
                        g++;
                    }
                    else if (c == 'M')
                    {
                        m++;
                    }
                    else
                    {
                        p++;
                    }
                }
                if (p != 0)
                {
                    lastp = i;
                }

                if (m != 0)
                {
                    lastm = i;
                }

                if (g != 0)
                {
                    lastg = i;
                }

                res += garb[i].size();
            }

            vector<int> pref(n - 1, 0);

            pref[0] = travel[0];

            for (int i = 1; i < n - 1; i++)
            {
                pref[i] = travel[i] + pref[i - 1];
            }

            if (lastg > 0)
            {
                res = res + pref[lastg - 1];
            }

            if (lastm > 0)
            {
                res += pref[lastm - 1];
            }

            if (lastp > 0)
            {
                res += pref[lastp - 1];
            }

            return res;
        }
};