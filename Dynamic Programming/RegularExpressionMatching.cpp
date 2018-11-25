class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (p[i - 1] == '*' && i >= 2)
                dp[0][i] = dp[0][i - 2];
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    if (j >= 2 && p[j - 2] != s[i - 1] && p[j - 2] != '.')
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                    else
                    {
                        dp[i][j] = ((j >= 2 && dp[i][j - 2]) || (j >= 2 && dp[i - 1][j - 2]) || dp[i - 1][j]);                    
                    }
                }
            }
        }

        return dp[m][n];
    }
};
