// 第一种解法
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= coins.size(); i++)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++)
            {
                if (j - coins[i - 1] >= 0)
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};

// 第二种解法
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                dp[j] = dp[j] + (j - coins[i] >= 0 ? dp[j - coins[i]] : 0);
            }
        }

        return dp[amount];
    }
};
