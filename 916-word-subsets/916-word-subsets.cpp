class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<string> res;
        res.clear();
        int freq[26] = {0};
        for(int i = 0; i < words2.size(); i++)
        {
            int count[26] = {0};
            for(int j = 0; j < words2[i].size(); j++)
            {
                count[words2[i][j] - 'a'] ++;
            }
            for(int j = 0 ; j < 26; j++) freq[j] = max (freq[j], count[j]);
        }
        
        for(int i = 0; i < words1.size() ; i++)
        {
            int count[26] = {0};
            bool flag = true;
            for(int j = 0; j < words1[i].size(); j++)
            {
                count[words1[i][j] - 'a'] ++;
            }
            
            for(int j = 0 ; j < 26; j++) 
            {
                if(count[j] < freq[j])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag) res.push_back(words1[i]);
        }
        return res;
    }
};