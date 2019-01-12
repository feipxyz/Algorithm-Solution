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
        int m = matrix.size();
        int n = matrix[0].size();

        int up = 0;
        int right = n - 1;
        int bottom = m - 1;
        int left = 0;
        int total = 0;
        while (up <= bottom && right >= left)
        {
            if (matrix[up][right] > target)
            {
                right--;
            }
            else if (matrix[up][right] == target)
            {
                total++;
                right--;
            }
            else if (matrix[up][right] < target)
            {
                up++;
            }

            if (up > bottom || right < left)
            {
                break;
            }

            if (matrix[bottom][left] < target)
            {
                left++;
            }
            else if (matrix[bottom][left] == target)
            {
                total++;
                left++;
            }
            else if (matrix[bottom][left] > target)
            {
                bottom--;
            }
        }
        return total;
    }
};
