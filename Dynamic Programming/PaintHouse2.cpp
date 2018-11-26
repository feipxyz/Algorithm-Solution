class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        if (costs.empty() || costs[0].empty()) return 0;
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> dp(n, vector<int>(k, 0));
        int nFirstMin = -1;
        int nSecondMin = -1;
        for (int i = 0; i < n; i++)
        {
            int lastFirst = nFirstMin;
            int lastSecond = nSecondMin;
            nFirstMin = -1;
            nSecondMin = -1;
            for (int j = 0; j < k; j++)
            {
                if (j != lastFirst)
                {
                    dp[i][j] = costs[i][j] + (lastFirst != -1 ? dp[i - 1][lastFirst] : 0);
                }
                else
                {
                    dp[i][j] = costs[i][j] + (lastSecond != -1 ? dp[i - 1][lastSecond] : 0);
                }

                if (nFirstMin == -1 || dp[i][j] < dp[i][nFirstMin])
                {
                    nSecondMin = nFirstMin;
                    nFirstMin = j;
                }
                else if (nSecondMin == -1 || dp[i][j] < dp[i][nSecondMin])
                {
                    nSecondMin = j;
                }
            }
        }
        return dp.back()[nFirstMin];
    }
};
