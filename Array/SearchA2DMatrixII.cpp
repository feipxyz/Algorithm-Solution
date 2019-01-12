class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        // write your code here
        int total = 0;
        int row = matrix.size() - 1;
        int col = 0;
        while (row >= 0 && col < matrix[0].size())
        {
            if (matrix[row][col] > target)
            {
                row--;
            }
            else if (matrix[row][col] < target)
            {
                col++;
            }
            else
            {
                total++;
                row--;
                col++;
            }
        }

        return total;
    }
};
