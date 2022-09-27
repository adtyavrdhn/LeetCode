class Solution
{
    public:
        string pushDominoes(string s)
        {
            string res;
            int n = s.size();
            int left = -1, right = s.size();

            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'R')
                {
                    right = i;
                    break;
                }
            }

            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'L')
                {
                    left = i;
                    break;
                }
            }

            vector<int> larr(n, INT_MAX);
            vector<int> rarr(n, INT_MAX);

            for (int i = left; i >= 0; i--)
            {
                if (s[i] == 'L')
                {
                    larr[i] = 0;
                }
                else if (i < n - 1 && s[i] == '.' && larr[i + 1] != INT_MAX)
                {
                    larr[i] = larr[i + 1] + 1;
                }
            }

            for (int i = right; i < n; i++)
            {
                if (s[i] == 'R')
                {
                    rarr[i] = 0;
                }
                else if (i >= 1 && s[i] == '.' && rarr[i - 1] != INT_MAX)
                {
                    rarr[i] = rarr[i - 1] + 1;
                }
            }

//             for (auto i: larr)
//             {
//                 cout << i << " ";
//             }
//             cout << endl;

//             for (auto i: rarr)
//             {
//                 cout << i << " ";
//             }
//             cout << endl;
            
            for(int i=0;i<n;i++)
            {
                if(larr[i]<rarr[i])
                {
                    res.push_back('L');
                }
                else if(rarr[i]<larr[i])
                {
                    res.push_back('R');
                }
                else res.push_back('.');
            }

            return res;
        }
};