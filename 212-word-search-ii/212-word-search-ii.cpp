struct Node
{
    Node *links[26];	// Links

    bool flag = false;	// EOW

    bool contains(char c)
    {
        return links[c - 'a'] != NULL;
    }

    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }
    Node* get(char c)
    {
        return links[c - 'a'];
    }
};
class Solution
{
    public:
        vector<string> res;
    vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
    {
        Node *root = new Node();

        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i], root);
        }

        Node *node = root;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                string temp;
                f(board, i, j, node,temp);
            }
        }
        
        return res;
    }
    void f(vector<vector < char>> &board, int i, int j, Node *node, string& temp)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == '#')
        {
            return;
        }
        
        node = node->get(board[i][j]);
        
        if(!node)
            return;
        
        char c = board[i][j];
        
        temp+= board[i][j]; 
        
        if (node->flag)
        {
            res.push_back(temp);
            node->flag = false;
        }
        
        board[i][j] = '#';
        

        f(board, i - 1, j, node, temp);
        f(board, i + 1, j, node, temp);
        f(board, i, j - 1, node, temp);
        f(board, i, j + 1, node, temp);

        board[i][j] = c;
        
        temp.pop_back();
    }
    void insert(string word, Node *root)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->contains(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->flag = true;
    }
};