class Solution
{
    public:
        vector<string> res;
    struct Node
    {
        Node *links[26];
        bool flag = false;
        void put(char c, Node *node)
        {
            links[c - 'a'] = node;
        }
        Node* get(char c)
        {
            return links[c - 'a'];
        }
        bool contains(char c)
        {
            return links[c - 'a'] != NULL;
        }
    };
    Node *root = new Node();
    vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
    {

        for (auto i: words)
        {
            Node *node = root;

            for (auto j: i)
            {
                if (!node->contains(j))
                {
                    node->put(j, new Node());
                }
                node = node->get(j);
            }
            node->flag = true;
        }

        int m = board.size(), n = board[0].size();

        Node *node = root;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string temp;
                f(board, i, j, temp, node);
            }
        }

        return res;
    }
    void f(vector<vector < char>> &board, int i, int j, string &temp, Node *node)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == '#')
        {
            return;
        }

        node = node->get(board[i][j]);

        if (!node)
            return;	// no word with this character
        
        // getting here means we have that character in our trie
        char c = board[i][j];
        temp+= c;
        
        if(node->flag)
        {
            res.push_back(temp);
            node->flag = false; // we took the word from here so we need to make sure we don't pick this word again
        }
        
        board[i][j]='#';
        
        f(board,i+1,j,temp,node);
        f(board,i,j+1,temp,node);
        f(board,i,j-1,temp,node);
        f(board,i-1,j,temp,node);
        
        
        board[i][j] = c; // backtracking
        temp.pop_back();
        
    }
};