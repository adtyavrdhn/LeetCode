class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int n = chars.size();

            if (chars.size() == 1)
                return 1;

            int index = 0;

            char last = '\0';
            bool flag = false;
            int count = 0;
            
            for (int i = 0; i < n; i++)
            {
                if (last=='\0' || last == chars[i])
                {
                    last = chars[i];
                    count++;
                }
                else
                {
                    char temp = chars[i];

                    chars[index++] = last;

                    if (count > 1)
                    {
                        string size = to_string(count);

                        for (int i = 0; i < size.size(); i++)
                        {
                            chars[index++] = size[i];
                        }
                    }
                    last = chars[i];
                    count = 1;
                }
            }

            if (count>=1)
            {
                chars[index++] = last;

                if (count > 1)
                {
                    string size = to_string(count);

                    for (int i = 0; i < size.size(); i++)
                    {
                        chars[index++] = size[i];
                    }
                }
            }

            return index;
        }
};