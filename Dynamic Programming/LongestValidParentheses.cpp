class Solution {
public:
    int longestValidParentheses(string s) {
        int nMax = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                dp[i] = 0;
            }
            else
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                }
                else
                {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    {

                        dp[i] = i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] -2] + dp[i - 1] + 2 : dp[i - 1] + 2;
                    }
                }
                nMax = max(nMax, dp[i]);
            }
        }

        return nMax;
    }
};
