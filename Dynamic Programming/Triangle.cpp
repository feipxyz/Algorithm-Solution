class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[triangle.size() - 1].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[m - 1] = triangle[m - 1];
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j] = min(dp[i][j], min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]);
            }
        }

        return dp[0][0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp = triangle.back();

        for (int layer = m - 2; layer >= 0; layer--)
        {
            for (int i = 0; i < triangle[layer].size(); i++)
            {
                dp[i] = min(dp[i], dp[i + 1]) + triangle[layer][i];
            }
        }

        return dp[0];
    }
};
