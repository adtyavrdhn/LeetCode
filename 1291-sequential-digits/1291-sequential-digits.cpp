class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
         vector<int> res;

        queue<int> q;
        
	
        for(int i = 1; i <= 9; i++)
        {
            q.push(i);
        }
        

        while(!q.empty())
        {
            int num = q.front();
            q.pop();
            
            int last = num % 10;
            int next = (num * 10) + (last + 1);
            
            if(num >= low) 
            {
                res.push_back(num);
            }
            
            if(last != 9 && next <= high) 
            {
                q.push(next);
            }
        }
        
        return res;
    }
};