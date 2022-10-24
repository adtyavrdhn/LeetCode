# User function Template for Python3

class Solution:
    def maxGold(self, n, m, M):
        def f(i,j,M,dp)->int:
            if(i<0 or j>=len(M[0]) or i>=len(M)):
                return 0
            if(dp[i][j]!=-1):
                return dp[i][j]
                
            upright = M[i][j] + f(i-1,j+1,M,dp)
            right = M[i][j] + f(i,j+1,M,dp)
            downright = M[i][j] + f(i+1,j+1,M,dp)
        
            dp[i][j]=max(upright,right,downright)
            
            return dp[i][j]
            
        res = 0
        dp = [[-1 for i in range(m)]for j in range(n)]
        for i in range(0,n):
            res = max(res,f(i,0,M,dp))
        return res


#{ 
 # Driver Code Starts
# Initial Template for Python3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, m = [int(x) for x in input().split()]
        tarr = [int(x) for x in input().split()]
        M = []
        j = 0
        for i in range (n):
            M.append(tarr[j:j + m])
            j = j+m
        
        ob = Solution()
        print(ob.maxGold(n, m, M))
# } Driver Code Ends