class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                dp[i] = nums[i];
            else if (i == 1)
                dp[i] = max(nums[i], nums[i - 1]);
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int last1 = 0;
        int last2 = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cur = max(nums[i] + last2, last1);
            last2 = last1;
            last1 = cur;
        }
        return cur;
    }
};
