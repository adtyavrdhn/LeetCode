class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int n = chars.size();
            stack<char> st;

            if (chars.size() == 1)
                return 1;

            int index = 0;

            for (int i = 0; i < n; i++)
            {
                if (st.empty() || st.top() == chars[i])
                {
                    st.push(chars[i]);
                }
                else
                {
                    char temp = chars[i];

                    chars[index++] = st.top();

                    if (st.size() > 1)
                    {
                        string size = to_string(st.size());

                        for (int i = 0; i < size.size(); i++)
                        {
                            chars[index++] = size[i];
                        }
                    }

                    st = {};

                    st.push(temp);
                }
            }

            if (!st.empty())
            {
                chars[index++] = st.top();

                if (st.size() > 1)
                {
                    string size = to_string(st.size());

                    for (int i = 0; i < size.size(); i++)
                    {
                        chars[index++] = size[i];
                    }
                }
            }

            return index;
        }
};