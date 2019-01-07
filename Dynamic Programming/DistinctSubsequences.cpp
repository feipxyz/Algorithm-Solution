class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (i < j)
                    continue;

                if (i == j)
                {
                    dp[i][j] = (s.substr(0, i) == t.substr(0, j));
                }
                else
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
