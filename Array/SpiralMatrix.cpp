class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int rowBegin = 0;
        int rowEnd = m - 1;
        int colBegin = 0;
        int colEnd = n - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            for (int i = colBegin; i <= colEnd; i++)
                res.push_back(matrix[rowBegin][i]);
            rowBegin++;
            if (rowBegin > rowEnd)
                break;

            for (int i = rowBegin; i <= rowEnd; i++)
                res.push_back(matrix[i][colEnd]);
            colEnd--;
            if (colBegin > colEnd)
                break;

            for (int i = colEnd; i >= colBegin; i--)
                res.push_back(matrix[rowEnd][i]);
            rowEnd--;
            if (rowBegin > rowEnd)
                break;

            for (int i = rowEnd; i >= rowBegin && rowBegin <= rowEnd; i--)
                res.push_back(matrix[i][colBegin]);
            colBegin++;
        }

        return res;
    }
};
