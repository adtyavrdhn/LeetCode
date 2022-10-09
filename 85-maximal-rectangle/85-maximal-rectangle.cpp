class Solution {
public:
    int f(vector<int>& arr) 
    {
        stack<int> st;
        
        int n = arr.size();
        
        int res = 0;
        
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i]))
            {
                int height = arr[st.top()]; // the last height which will be stored in variable height will keep the tower we are currently calculating for
                st.pop();
                
                int width = 0;
                
                if(st.empty())
                    width = i;
                
                else width = i-st.top()-1; // st.top() is left smaller index while i is the right smaller index
                
                res = max(res, width*height);
                
            }
            st.push(i);
        }
        
        return res;
    }
    int maximalRectangle(vector<vector<char>>& grid) 
    {
        
        int m = grid.size();
        int n = grid[0].size();
    
        vector<vector<int>> matrix(m , vector<int> (n,0));
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j] = grid[i][j]-'0';
            }
        }
        
        vector<int> prev = matrix[0];
        int res = f(prev);
        
       
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j])
                    prev[j]++;
                else
                    prev[j]=0;
            }
            
            res = max(res, f(prev));
        }
        return res;
    }
};