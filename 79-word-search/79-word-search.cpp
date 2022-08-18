class Solution
{
    public:
        vector<vector < int>> d = {
		{ -1, 0 },
            { 0,
                -1 },
            { 1,
                0 },
            { 0,
                1 }
        };
    bool exist(vector<vector < char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (f(board, 0, i, j, word))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool f(vector<vector < char>> &board, int index, int i, int j, string word)
    {
        if (index == word.size())
        {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }

        bool res = false;

        char temp = board[i][j];
        board[i][j] = ' ';

        for (int k = 0; k < 4; k++)
        {
            int nx = i + d[k][0];
            int ny = j + d[k][1];

            res = res || f(board, index + 1, nx, ny, word);
        }

        board[i][j] = temp;

        return res;
    }
};