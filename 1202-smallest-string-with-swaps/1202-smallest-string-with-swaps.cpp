class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    // Initialize the array root and rank
    // Each vertex is representative of itself with rank 1
    UnionFind(int sz) : root(sz), rank(sz) 
    {
        for (int i = 0; i < sz; i++) 
        {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    // Get the root of a vertex
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    // Perform the union of two components
    void unionSet(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            } else {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        
        // Iterate over the edges
        for (vector<int> edge : pairs) {
            int source = edge[0];
            int destination = edge[1];
            
            // Perform the union of end points
            uf.unionSet(source, destination);
        }
        
        
        unordered_map<int, vector<int>> rootToComponent;
        // Group the vertices that are in the same component
        for (int vertex = 0; vertex < s.size(); vertex++) 
        {
            int root = uf.find(vertex);
            // Add the vertices corresponding to the component root
            rootToComponent[root].push_back(vertex);
        }
        
        // String to store the answer
        string smallestString(s.length(), ' ');
        // Iterate over each component
        for (auto component : rootToComponent) 
        {
            vector<int> indices = component.second;
            
            // Sort the characters in the group
            vector<char> characters;
            for (int index : indices) {
                characters.push_back(s[index]);
            }
            sort(characters.begin(), characters.end());
            
            // Store the sorted characters
            for (int index = 0; index < indices.size(); index++) {
                smallestString[indices[index]] = characters[index];
            }
        }
        
        return smallestString;
    }
};