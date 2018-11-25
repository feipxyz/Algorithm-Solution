class Solution {
public:
    int rob(vector<int>& nums) {
        int nMax = 0;
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                dp[i] = nums[i];
            }
            else if (i == 1)
            {
                dp[i] = max(dp[i - 1], nums[i]);
            }
            else
            {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
            nMax = max(nMax, dp[i]);
        }

        return nMax;
    }
};
