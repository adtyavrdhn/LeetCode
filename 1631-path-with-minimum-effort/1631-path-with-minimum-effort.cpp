class Solution
{
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    // we have defined the change in coordinate if they move in specific directions 

    bool isvalid(int x, int y, int n, int mid)
    {
        return (x >= 0 && x < n && y >= 0 && y < mid);
        // to check whether on which path we are moving is valid or not 
    }


    bool bfs(vector<vector<int>> heights, int k)
    {
        queue<pair<int, int>> q;
        // queue to perform the BFS logic 
        q.push({0, 0});
        // initially push the first cell of matrix 
        vector<vector<bool>> visited(101, vector<bool>(101, false));
        // make a visisted array initially with all the value false initially 
        visited[0][0] = 1;
        // since it visited , makr it a true  

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            // pick out the front 
            q.pop();
            int cx = curr.first;
            int cy = curr.second;
            // get the current x and y 
            if (cx == heights.size() - 1 && cy == heights[0].size() - 1)
                return true;
            // if we are reached the last index we are done
            // else just go in all 4 direction and check conditions  
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + cx;
                int y = dy[i] + cy;
                // each time make new x , y 
                if (isvalid(x, y, heights.size(), heights[0].size()) && !visited[x][y])
                {
                    // if that x,y is valid , just check tah absolute difference is less tha tha mid or not 
                    if (abs(heights[cx][cy] - heights[x][y]) <= k)
                    {
                        visited[x][y] = true;
                        // if yes visit that node 
                        q.push({x, y});
                        // push it in queue 
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // we have similar binary search template  

        int low = 0;
        int high = 1e6;
        int ans = -1;

        // set high and low  

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // get a mid 
            // apply bfs over that mid value 
            if (bfs(heights, mid))
            {
                // if that bfs on that value return true , it might be our answer , so store it 
                ans = mid;
                high = mid - 1;
                // since we want want min value , high=mid-1
            }
            else
            {
                low = mid + 1;
                // else increase the value and check for it 
            }
        }
        return ans;
        //  return the ans 
    }
    
};