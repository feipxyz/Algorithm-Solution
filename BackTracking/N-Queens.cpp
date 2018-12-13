class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n, 0);
        vector<vector<string>> ret;

        NQueens(0, n, queens, ret);

        return ret;
    }

    void NQueens(int row, int n, vector<int> queens, vector<vector<string>>& ret)
    {
        if (row == n)
        {
            vector<string> ans(n, string(n, '.'));
            for (int i = 0; i < n; i++)
            {
                ans[i][queens[i]] = 'Q';
            }
            ret.push_back(ans);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            queens[row] = i;
            if (is_ok(row, queens))
                NQueens(row + 1, n, queens, ret);
        }
    }

    bool is_ok(int row, vector<int> queens)
    {
        for (int i = 0; i < row; i++)
        {
            if (queens[row] == queens[i] || row + queens[row] == i + queens[i] || row - queens[row] == i - queens[i])
                return false;
        }

        return true;
    }
};
