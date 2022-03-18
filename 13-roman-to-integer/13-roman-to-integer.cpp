class Solution {
public:
    int romanToInt(string s) 
    { unordered_map <char, int> dict {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (dict[s[i]] < dict[s[i+1]]) result -= dict[s[i]];
            else { result += dict[s[i]]; }
        }
        
        return result;
    }
};