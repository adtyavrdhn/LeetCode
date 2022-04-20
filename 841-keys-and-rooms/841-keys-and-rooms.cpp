class Solution
{
    public:
        bool canVisitAllRooms(vector<vector < int>> &rooms)
        {
            vector<bool> unlocked(rooms.size(),false);

            queue<int> q;
            q.push(0);
 
            while (!q.empty())
            {
                int i = q.front();
                q.pop();

                if (unlocked[i])
                    continue;

                unlocked[i] = true;

                for (int key: rooms[i])
                    if (!unlocked[key])
                        q.push(key);
            }

            for (bool x: unlocked)
                if (!x)
                    return false;

            return true;
        }
};