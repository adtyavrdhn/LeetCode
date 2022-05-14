class Solution {
public:
    int divisorSubstrings(int num, int k) 
    {
        string s = to_string(num);
        
        int count = 0;
        for(int i=0;i<s.size();i++)
        {     
            string div = "";
            div = s.substr(i,k);
            if(div.size()==k)
            {
              int d = stoi(div);
                
                if(d!=0)
              if(num % d == 0) count++;
            }
           
        }
        
        return count;
    }
};