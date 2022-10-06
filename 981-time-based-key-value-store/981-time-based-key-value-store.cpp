class TimeMap
{
    public:
    TimeMap() {}
    unordered_map<string, map<int, string>> mpp;

    void set(string key, string value, int timestamp)
    {
        mpp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto it = mpp[key].upper_bound(timestamp);
        
        if (it == mpp[key].begin()) return "";
        
        it--;
        return it->second;
    }
};