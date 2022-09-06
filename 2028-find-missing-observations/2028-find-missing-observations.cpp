class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
       int m = rolls.size();
       int target = (m+n)*mean - accumulate(rolls.begin(),rolls.end(),0);

        if(target > (n*6) || (n>target)) // more than all 6sand less than all 1s, impossible scenario
            return {};
        
        
        vector<int> res;
        
        while(target != 0)
        {
            int dice = min(target-n+1,6);
            
            res.push_back(dice);
            
            target-=dice;
            
            n--;
        }
        
        return res;
        
    }
};