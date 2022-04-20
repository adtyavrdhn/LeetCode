class Solution
{
    public:
        vector<bool> unlocked;
    void dfs(vector<vector < int>> &rooms, int i)
    {
        if (unlocked[i])
            return;

        unlocked[i] = true;

      
        for (auto key: rooms[i])
            dfs(rooms, key);
    }
    public:
        bool canVisitAllRooms(vector<vector < int>> &rooms)
        {
            unlocked = vector<bool> (rooms.size());

            dfs(rooms, 0);

            for (auto x: unlocked)
                if (!x)
                    return false;

            return true;
        }
};