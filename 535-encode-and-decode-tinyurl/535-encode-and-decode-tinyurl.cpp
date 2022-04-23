class Solution {
public:

    unordered_map<string,string> mpp;
    int n = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        n++;
        string add = to_string(n);
        string res = "http://tinyurl.com/";
        res+=add;
        mpp[res] = longUrl;
        return res;
            
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));