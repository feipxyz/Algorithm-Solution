class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[y].size(); x++)
            {
                if (Find(board, word, y, x, 0))
                    return true;
            }
        }
        return false;
    }

    bool Find(vector<vector<char>>& board, string word, int y, int x, int i)
    {
        if (i == word.size())
            return true;
        if (y < 0 || x < 0 || y >= board.size() || x >= board[y].size())
            return false;
        if (board[y][x] != word[i])
            return false;
        char tmp = board[y][x];
        board[y][x] = '\0';

        bool res = Find(board, word, y, x + 1, i + 1) || Find(board, word, y, x - 1, i + 1)
                   || Find (board, word, y + 1, x, i + 1) || Find(board, word,y - 1, x, i + 1);
        board[y][x] = tmp;
        return res;
    }
};
